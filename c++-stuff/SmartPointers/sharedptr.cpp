#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(const std::string& name) : _name(name)
    {
        std::cout << "MyClass (" << _name << ") created\n";
    }

    ~MyClass()
    {
        std::cout << "MyClass (" << _name << ") destroyed\n";
    }

    void printName()
    {
        std::cout << "Hi! I am " << _name << "\n";
    }

private:
    std::string _name;
};



std::shared_ptr<MyClass> createClass(const std::string& name)
{
    std::shared_ptr<MyClass> mc = std::make_shared<MyClass>(name);
    std::cout << "in createClass function...\n";
    return mc;
}


int main()
{
    std::shared_ptr<MyClass> outerShared;
    std::weak_ptr<MyClass> weakPtr;
    std::cout << "start-----------------------------\n";
    {
        std::shared_ptr<MyClass> sharedPtr = createClass("shared class");
        sharedPtr->printName();
        weakPtr = sharedPtr;
        //sharedPtr.reset(new MyClass("NEW Shared"));
        outerShared = sharedPtr;
        std::cout << "end of inner scope\n";
    }
    std::cout << "end-----------------------------\n";

    if (outerShared.get() == nullptr)
    {
        std::cout << "outer shared pointer is null :(\n";
    }
    else
    {
        std::cout << "yey! outer shared pointer is not null! :)\n";
        outerShared->printName();
    }
    //if(weakPtr.expired());
    if (auto shPtr = weakPtr.lock())
    {
        shPtr->printName();
    }
    else
    {
        std::cout << "weak ptr is dead :(\n";
    }

    std::cout << "end of main scope\n";
    return 0;
}
