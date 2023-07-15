#include <iostream>

class Right
{
public:
    void print()
    {
        std::cout << "Right" << std::endl;
    }
};

class Left{
public:
    void print()
    {
        std::cout << "Left" << std::endl;
    }
};

class Bottom: public Right, public Left
{
public:
/*    void print()
    {
        std::cout << "Bottom" << std::endl;
    }
*/
    void foo()
    {
        Left::print();
    }
    virtual void greet()
    {
        std::cout << "Hello!" << std::endl;
    }
};

class Forest: public Bottom
{
public:
    void greet()
    {
        std::cout << "Hi!" << std::endl;
    }

};

class Black: public Forest
{
public:
    void action()
    {
        greet();
    }
};
                            
int main()
{
    Bottom B;
    //B.Left::print();
    B.foo();

    Black blck;
    blck.action();
    blck.foo();

    return 0;
}
