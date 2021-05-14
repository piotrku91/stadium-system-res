#pragma once
#include "person.hpp"
#include <memory>
#include <map>

class seat // Abstract class
{

protected:
    std::string m_Name;
    int m_Price;

public:
    //Pure virtual functions
    virtual void initName() = 0;

    void initPrice(std::string byName){

    };
    // std::shared_ptr<Person> TicketOwner; ?

public:
    std::string getName() const { return m_Name; };
    int getPrice() const { return m_Price; }
    bool reserveSeat(const Person &PersonToSit);
    bool swapSeat(const Person &PersonToSit1, const Person &PersonToSit2);

public:
    seat(std::map<std::string, int> &priceList){};
};

class Standard : seat
{

    void initName() { m_Name = "Standard"; };

public:
    Standard(std::map<std::string, int> &priceList) : seat(priceList)
    {
        initName();
        initPrice(m_Name);
    };
};