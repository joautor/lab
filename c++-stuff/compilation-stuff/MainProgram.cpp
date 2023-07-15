#include <iostream>
#include "MyClass.h"

int main()
{
    MyClass mc("myclass baby");
    std::cout << mc.getName() << std::endl;
    return 0;
}
