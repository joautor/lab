#include "MyD.hpp"

MyD::MyD(const std::string& name) : m_DName(name)
{
}

void MyD::foo()
{
    std::cout << "Doing Something from inside foo()....." << std::endl;
}
void MyD::setD(const std::string& newName)
{
    m_DName = newName;
}
std::string MyD::getD()
{
    return m_DName;
}

void MyD::print()
{
    std::cout << "MyD is \"" << m_DName << "\"" << std::endl;
}
