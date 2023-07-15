#include <iostream>
#include <vector>

class MyVertices {
public:
    MyVertices(int a, int b , int c): _a(a), _b(b), _c(c)
    {
    }

    MyVertices(const MyVertices& mv) : _a(mv._a), _b(mv._b), _c(mv._c)
    {
        std::cout << "copied!\n";
    }

    int _a;
    int _b;
    int _c;
};

int main()
{
    std::vector<MyVertices> myVer;
    myVer.reserve(3);
    //myVer.push_back(MyVertices{1, 2, 3});
    //myVer.push_back(MyVertices{4, 5, 6});
    //myVer.push_back(MyVertices{7, 8, 9});

    myVer.emplace_back(1, 2, 3);
    myVer.emplace_back(4, 5, 6);
    myVer.emplace_back(7, 8, 9);

    // In summary, if you have an idea how many items will the vector have, reseve it first. As you can see, the vector initially have a 
    // a certain capacity. When the vector reaches the maximum capacity,as you add more items to it, it will create a new vector (not sure but i think double the current size).
    // Then it will copy the items to the new vector with the ajusted size (capacity).
    // Always use emplace_back istead of push_back. With emplace back we can forward the class arguments directly as the item is created and added to the vector. 
    // With push_back, we need to create the object first then add to the vector which have an extra copying.

}
