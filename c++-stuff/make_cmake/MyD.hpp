#pragma once

#include <string>
#include <iostream>

class MyD
{
public:
    MyD() = default;
    MyD(const std::string& name);
    ~MyD() = default;

    void foo();
    void setD(const std::string& newName);
    std::string getD();
    void print();

private:
    std::string m_DName;
};
