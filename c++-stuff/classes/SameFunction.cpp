#include <iostream>

class Parent
{
public:
    virtual void foo()
    {
        std::cout << "foo from parent" << std::endl;
    }
    void action()
    {
        std::cout << "action!" << std::endl;
    }
};

class Child : public Parent {
public:
    void foo()
    {
        std::cout << "foo form child" << std::endl;
    }
    void fooParent()
    {
        Parent::foo();
    }
};

void myfunc(Parent* ptr)
{
    std::cout << "calling myfunc" << std::endl;
    ptr->foo();
}

int main()
{
    Child c;
    c.foo();
    c.action();
    c.fooParent();

    Parent p;
    p.foo();

    myfunc(&c);
    myfunc(&p);

    return 0;
}
