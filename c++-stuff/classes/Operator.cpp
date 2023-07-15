#include <iostream>

class CustomNum
{
public:
    CustomNum( int num) : num(num) {};
    ~CustomNum() = default;

    bool operator>=(CustomNum& other)
    {
        std::cout << "this val: " << this->getVal() << ", other val: " << other.getVal() << std::endl;
        return this->getVal() >= other.getVal();
    }

    void operator++()
    {
        std::cout << "adding 1 to " << this->getVal();
        ++num;
        std::cout << " = " << this->getVal() << std::endl;
    }

    CustomNum operator+(CustomNum& other)
    {
        std::cout << "thisVal(" << this->getVal() << ") +  otherVal(" << other.getVal() << ")" << std::endl;
        CustomNum newNum(this->getVal() + other.getVal());
        return newNum;
    }

    void dumpNum()
    {
        std::cout << "numValue is: " << num << std::endl;
    }

private:
    int num;

    int getVal()
    {
        return num;
    }
};

int main()
{
    std::cout << "Hello World!" << std::endl;

    CustomNum num1(7);
    CustomNum num2(17);

    if ( num1 >= num2)
    {
        std::cout << "num1 is greater than or equal to  num2" << std::endl;
    }
    else
    {
        std::cout << "num1 is lesser than num2" << std::endl;
    }

    ++num1;
    num1.dumpNum();

    CustomNum num3 = num1 + num2;
    num3.dumpNum();

    return 0;
}
