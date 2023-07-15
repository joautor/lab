#include "MyClass.h"

MyClass::MyClass(std::string name) : _name(name) {}

std::string MyClass::getName()
{
    return _name;
}
