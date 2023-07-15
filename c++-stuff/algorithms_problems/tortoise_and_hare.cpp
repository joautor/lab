#include<iostream>
#include<vector>

int findDuplicate(std::vector<int>& vec)
{
    int tortoise = vec.front();
    int hare = vec.front();

    do {
        tortoise = vec[tortoise];
        hare = vec[vec[hare]];
    } while (tortoise != hare);

    int elem1 = vec.front();
    int elem2 = tortoise;

    while (elem1 != elem2)
    {
        elem1 = vec[elem1];
        elem2 = vec[elem2];
    }
    return elem1;
}

int main()
{
    std::vector<int> num = {9, 1, 3, 8, 7, 3, 6, 4, 5, 2};
    std::cout << "Duplicate num is: " << findDuplicate(num) << std::endl;
    return 0;
}

