#include "sorter.h"
#include "logger.h"

#define STEP(SIZE,OFFSET) ((SIZE) * (OFFSET))

void bubbleSort(void* array, int arrSize, int (*compareFunc)(void* item1, void* item2), void (*swapFunc)(void* item1, void* item2), size_t itemSize)
{
    //LOG_DBG("");
    for(int i = 0; i < arrSize; ++i) {
        for(int j = 0; j <  (arrSize - 1 - i); ++j) {
            if (0 < compareFunc((array + STEP(itemSize, j)), (array + STEP(itemSize, j + 1)))) {
                swapFunc((array + STEP(itemSize, j)), (array + STEP(itemSize, j + 1)));
            }
        }
    }
}

void MergeSort(void* array, int arrSize, int (*compareFunc)(void* item1, void* item2), void (*swapFunc)(void* item1, void* item2), size_t itemSize)
{
    // ToDo: Implement
    LOG_ERR("Not yet implemented!");
}
