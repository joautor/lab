#include <iostream>
#include <string>


template <class T>
T doubleIt( T val)
{
    return val + val;
}

int main()
{
    std::cout << "Double 5: " << doubleIt(5) << std::endl;
    std::cout << "Double 1.5 " << doubleIt(1.5) << std::endl;
    std::cout << "Double true " << std::boolalpha << doubleIt(true) << std::endl;
    //std::cout << "Double const char* \"Hello\": " << doubleIt("Hello") << std::endl;
    std::string myStr = "World";
    std::cout << "Double string \"World\": " << doubleIt(myStr) << std::endl;

    return 0;
}
