#include <iostream>
#include <string>
#include <set>
#include <map>

class Record
{
public:
    int rank;
    std::string value;

    Record(int rank, std::string value) : rank(rank), value(value)
    {
    }

    bool operator<(const Record &r) const //required by set and map '<'
    {
        return rank < r.rank;
    }
};

int main()
{
    std::set<Record> s;
    std::map<Record, std::string> m;

    Record r1(3, "test");
    Record r2(1, "ok");

    m[r1] = "another string";

    s.insert(r1);
    s.insert(r2);

    for (const auto &rec : s)
    {
        std::cout << rec.rank << " : " << rec.value << "\n";
    }

    return 0;
}
