#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>


#define FCT 69

typedef enum Event
{
    evUploadFileResp
}Event;



typedef enum UploadResult
{
    Success,
    RfRejected,
    RfscRejected,
    UploadFailed,
    ConnectionError
}UploadResult;


class RFScanCollector
{
public:
    struct AntennaInfo
    {
    };

    enum class OperationType
    {
        capture,
        summary
    };

    struct RFScanData
    {
        int cellId = 0;
        int antId = 0;
        OperationType type = OperationType::capture;

    } typedef cellData;



    RFScanCollector() = default;
    ~RFScanCollector() = default;

    std::vector<RFScanData> getCellScanTasks(int cellId, const std::vector<int>& antennas)
    {
        std::vector<RFScanData> dataList;
        RFScanData scanData;
        for (const auto& antenna : antennas)
        {
            scanData.cellId = cellId;
            scanData.antId = antenna;
            scanData.type = OperationType::capture;
            dataList.push_back(scanData);
            std::cout << "added cell [" << cellId << "] with antena [" << antenna << "] to Scan Data List" << std::endl;
        }
        scanData.cellId = cellId;
        scanData.antId = 0;
        scanData.type = OperationType::summary;
        dataList.push_back(scanData);
        std::cout << "added summary for cell [" << cellId << "] to Scan Data List" << std::endl;

        return dataList;
    }

    void setCollectionDetails(std::vector<int>& cells, const std::vector<int>& antennas)
    {
        std::cout << "Setting Collection Details..." << std::endl;
        mObjectsStatus.clear();
        for (const auto& cell : cells)
        {
            const auto cellTasks = getCellScanTasks(cell, antennas);
            mScanDataList.insert(mScanDataList.end(), cellTasks.begin(), cellTasks.end());
            mObjectsStatus.emplace(std::make_pair(cell, std::make_pair(UploadResult::Success, 0)));
        }
        mObjectsStatus.emplace(std::make_pair(FCT, std::make_pair(UploadResult::Success, 0)));

        std::cout << "Collection Details Done" << std::endl;

    }

    void triggerCollection()
    {
        std::cout << "Start RF Scanning" << std::endl;
        mTasksQueue = mScanDataList;
        mDummyResults = mUploadResults;
        startNextScan();
    }

    void startNextScan()
    {
        if (!mTasksQueue.empty())
        {
            RFScanData cellData = mTasksQueue.front();
            if (OperationType::capture == cellData.type)
            {
                std::cout << "Task (cell: " << cellData.cellId << ", AntId: " << cellData.antId << ", type: capture)" << std::endl;
             //   std::cout << "Sending event blah blah" << std::endl;
                std::cout << "Sending evUploadFileReq..." << std::endl;
            }
            else if (OperationType::summary == cellData.type)
            {
                std::cout << "Task (cell: " << cellData.cellId << ", type: Summary" << std::endl;
                std::cout << "Sending evUploadFileReq..." << std::endl;
            }

            auto dummyresult = mUploadResults.empty() ? UploadResult::Success : mDummyResults.front();

            if (!mDummyResults.empty())
            {
            //    std::cout << "popping ---" << std::endl;
                mDummyResults.pop_front();
            }
           // std::cout << "trigger received event" << std::endl;
            receivedEvent(Event::evUploadFileResp, dummyresult);
        }
    }

    UploadResult getOverAllCellCycleResult()
    {
        auto antennaItr = std::find_if(mAntennaStatus.begin(), mAntennaStatus.end(), [] (const auto& elem)
        {
            return UploadResult::Success != elem.second;
        });

        if (antennaItr != mAntennaStatus.end())
        {
            return antennaItr->second;
        }
        return UploadResult::Success;
    }

    void evaluateAntennaScan(UploadResult result)
    {
        auto currentTask = mTasksQueue.front();
        if (OperationType::capture == currentTask.type)
        {
            mAntennaStatus.emplace(std::make_pair(currentTask.antId, result));
        }
        else if (OperationType::summary ==currentTask.type)
        {
            mAntennaStatus.emplace(std::make_pair(currentTask.antId, result));
            result = getOverAllCellCycleResult();
            auto currentObjectStatusIt = mObjectsStatus.find(currentTask.cellId);
            auto currentStatusPair = currentObjectStatusIt->second;

            if (result != currentStatusPair.first)
            {
                currentStatusPair.first = result;
                currentStatusPair.second = 0;
            }

            if (result != UploadResult::Success)
            {
                ++currentStatusPair.second;
            }

            mObjectsStatus[currentTask.cellId] = currentStatusPair;
            mAntennaStatus.clear();
        }
    }

    void receivedEvent(Event ev, UploadResult result)
    {
        if (Event::evUploadFileResp == ev)
        {
            std::cout << "received evUploadFileResp with upload result: " << result << std::endl;
            evaluateAntennaScan(result);
            mTasksQueue.pop_front();
            startNextScan();
        }
        else
        {
            std::cout << "ERROR: received unrecognized event! Event not handled" << std::endl;
        }
    }

    void dumpObjectsStatus()
    {
        for (const auto& elem : mObjectsStatus)
        {
            std::string unitName = elem.first == FCT ? "FCT" : "cell";
            std::cout << unitName << " " << elem.first << ", (" << elem.second.first << ", " << elem.second.second << ")\n";
        }
    }


private:
    std::map<int, std::pair<UploadResult, int>> mObjectsStatus;
    std::map<int, UploadResult> mAntennaStatus;
    std::list<RFScanData> mScanDataList, mTasksQueue;

    std::list<UploadResult> mUploadResults { Success, UploadFailed, UploadFailed, Success, Success};
    std::list<UploadResult> mDummyResults;
};


int main()
{
    std::cout << "hello world! HI MINE!!!" << std::endl;
    std::cout << "FCT is " << FCT << std::endl;

    std::vector<int> cells {1, 2, 3};
    std::vector<int> antennas {1};

    RFScanCollector scanCollector;
    scanCollector.setCollectionDetails(cells, antennas);
    scanCollector.triggerCollection();
    
    scanCollector.triggerCollection();

    scanCollector.dumpObjectsStatus();

    return 0;
}
