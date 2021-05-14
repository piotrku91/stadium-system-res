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
    //std::shared_ptr<Person> TicketOwner;
    std::string getName() const { return m_Name; };
    int getPrice() const { return m_Price; };
    // Prototypes 
    bool reserveSeat(const Person &PersonToSit);
    bool swapSeat(const seat& SecondSeat);

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