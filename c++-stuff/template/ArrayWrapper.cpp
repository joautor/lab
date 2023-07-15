#include <iostream>

template<class T, int Size>
class ArrayWrapper
{
public:
    ArrayWrapper(T* tempArr)
    {
        std::cout << "The size is " << Size << std::endl;
        //myArr = tempArr;
        for(int i = 0; i < Size; ++i)
        {
            myArr[i] = *(tempArr++);
        }
    }

    void print_all()
    {
        for(auto& elem : myArr)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    int size()
    {
        return Size;
    }
private:
    T myArr[Size];
};


int main()
{
    int test[5] = {4, 5, 6, 7, 8};
    ArrayWrapper<int, 5> aw = {test};//{1, 2, 3, 4, 5};
    aw.print_all();
}
