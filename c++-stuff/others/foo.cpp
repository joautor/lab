#include <iostream>

void foo(const std::string& name)
{
    std::cout << "Hello World! " << name << std::endl;
}

int main()
{
    std::string input{"babe"};
    foo(input);

    return 0;
}
