#pragma once
#include <string>
// This class is only demo version - need to be rebuild
class Person
{
private:
    size_t m_userID;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_phoneNumber;
    std::string m_email;
    std::string m_passportNumber;
    bool m_Vaccinated;

public:
    // Getters
    size_t getID() {return m_userID;};
    std::string getName() { return m_firstName; };
    std::string getlastName() { return m_lastName; };
    std::string getFullName() { return m_firstName + " " + m_lastName; };
    std::string getPhone() { return m_phoneNumber; };
    std::string getEmail() { return m_email; };
    std::string getPassport() { return m_passportNumber; }; 

    int getAge(); //(prototype - needs to be implemented)
                  //Constuctor
    Person(std::string firstName, std::string lastName, std::string passportNumber) : m_firstName(firstName), m_lastName(lastName), m_passportNumber(passportNumber){};
};