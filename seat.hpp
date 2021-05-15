#pragma once
#include "person.hpp"
#include <memory>
#include <map>
#include <string>

// This class is only demo version - need to be rebuild
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class seat // Abstract class
{

protected:
    mutable std::string m_Name;
    int m_Price;
    std::map<std::string, int> &Prices;
    virtual void initName() = 0; //Pure virtual function
public:
    void initPrice(std::string byName)
    {
        m_Price = Prices[byName];
    };
    //std::shared_ptr<Person> TicketOwner; //(prototype - needs to be implemented)
    std::string getName() const { return m_Name; };
    int getPrice() const { return m_Price; };
    // Prototypes 
    bool reserveSeat(const Person &PersonToSit); //(prototype - needs to be implemented)
    bool swapSeat(const seat& SecondSeat); //(prototype - needs to be implemented)
    bool isBusy(); //(prototype - needs to be implemented)

    // Constructor
    seat(std::map<std::string, int> &PriceMap) : Prices(PriceMap){};
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Standard : public seat // Standard seat class example
{
private:
    void initName() { m_Name = "Standard"; };

public:
    // Constructor
    Standard(std::map<std::string, int> &PriceMap) : seat(PriceMap)
    {
        initName();
        initPrice(m_Name);
    };
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////