#pragma once
class Person
{
private:
    std::string m_firstName;
    std::string m_lastName;

    Person(std::string firstName, std::string lastName) : m_firstName(firstName), m_lastName(lastName){};
};