#include <iostream>

class MyBase {
public:
    MyBase()
    {
        std::cout << "MyBase created" << std::endl;
    }

    virtual void talk()
    {
        std::cout << "This is Base talking" << std::endl;
    }
};

class MyDerive: public MyBase {
public:
    MyDerive()
    {
        std::cout << "MyDerive created" << std::endl;
    }
    virtual void talk() override
    {
        std::cout << "This is Derive talking" << std::endl;
    }

};

class BranchRight: public MyBase {
public:
    BranchRight()
    {
        std::cout << "Branch Right Created" << std::endl;
    }

    virtual void talk() override
    {
        std::cout << "This is BranchRight talking" << std::endl;
    }
};


// If MyDerive and BranchRight are derive here, it will caused an error: 'MyBase' is an ambiguous base of 'Center';
class Center: public MyDerive/*, public BranchRight*/ {
public:
    Center()
    {
        std::cout << "Center Created" << std::endl;
    }

    void talk() override
    {
        std::cout << "This is Center talking" << std::endl;
    }
};

void myfunc(MyBase* my)
{
    my->talk();
}

int main()
{
    std::cout << "Hello World" << std::endl;
    MyDerive md;
    myfunc(&md);
    std::cout << "---------------------------" << std::endl;
    MyBase mb;
    myfunc(&mb);
    std::cout << "---------------------------" << std::endl;
    BranchRight br;
    myfunc(&br);
    std::cout << "---------------------------" << std::endl;
    Center c;
    myfunc(&c);
    return 0;
}

/*
2021-04-08
Kinabahan ako sa suggestion ko (kay ceo) na gumawa ng virtual fuction para hindi hindi na need mag cast hahaha buti nalng tama yung iniisip
ko na behavior hahaha
*/
