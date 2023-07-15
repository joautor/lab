#include <iostream>
#include <sstream>
#include <exception>
#include <string>

class MyOnlyException : public std::exception {
public:
    MyOnlyException(const std::string& errMsg) : _errMsg(errMsg) {}

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }
private:
    std::string _errMsg;
};

void foo(bool isError)
{
    if (isError)
    {
        throw MyOnlyException("You're the I love! You're the one I need!");
    }
}

int main(int argc, char* argv[])
{
    bool isToThrow = (argc > 1 && std::string(argv[1]) == "true") ? true : false;
    try {
        foo(isToThrow);
    } catch (MyOnlyException e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    std::cout << "No error found!\n";
    return 0;
}
