#include <iostream>


bool one(bool res)
{
    std::cout << "one"<< std::endl;
    return res;
}

bool two(bool res)
{
    std::cout << "two" << std::endl;
    return res;
}

bool three(bool res)
{
    std::cout << "tree" << std::endl;
    return res;
}

int main()
{
    if (one(false) || two(true) && three(true)) {}
    
    return 0;
}
