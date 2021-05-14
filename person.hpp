#pragma once
#include <string>
// This class is only demo version - need to be rebuild
class Person
{
private:
    std::string m_firstName;
    std::string m_lastName;

public:
    //Constuctor
    Person(std::string firstName, std::string lastName) : m_firstName(firstName), m_lastName(lastName){};
};