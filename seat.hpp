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
    size_t m_SeatID;
    mutable std::string m_Name;
    int m_Price;
    std::map<std::string, int> &Prices; // Reference to prices list
    virtual void initName() = 0;        // Pure virtual function
    void initPrice(std::string &byName);

    seat(std::map<std::string, int> &PriceMap) : m_SeatID(Counter++), Prices(PriceMap){}; // Constructor (protected)

public:
    inline static size_t Counter; // Keeps actual amount of created seats.
    // Template of production function
    template <typename T>
    static std::unique_ptr<seat> createSeat(std::map<std::string, int> &PriceMap) // Produce new object of subclass
    {
        std::unique_ptr<seat> newSeat(new T(PriceMap));
        return newSeat;
    }

    // Getters functions
    std::string getName() const { return m_Name; };
    size_t getID() const { return m_SeatID; };
    void testName() { m_Name = ".."; }; // Test function to change something (temporary)
    int getPrice() const { return m_Price; };
    char getSymbol() { return getName()[0]; }; // Returns first char of name
    // Prototypes - TODO
    bool reserveSeat(const Person &PersonToSit); //(prototype - needs to be implemented)
    bool swapSeat(const seat &SecondSeat);       //(prototype - needs to be implemented)
    bool isBusy() const;                         //(prototype - needs to be implemented)
    //std::shared_ptr<Person> TicketOwner; //(prototype - needs to be implemented)
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Standard : public seat // Standard seat derived class
{
private:
    void initName() override { m_Name = "Standard"; };

public:
    // Constructor
    Standard(std::map<std::string, int> &PriceMap) : seat(PriceMap)
    {
        initName();
        initPrice(m_Name);
    }; // seat subclass constructor
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class VIP : public seat // VIP seat derived class
{
private:
    void initName() override { m_Name = "VIP"; };

public:
    // Constructor
    VIP(std::map<std::string, int> &PriceMap) : seat(PriceMap)
    {
        initName();
        initPrice(m_Name);
    }; // seat subclass constructor
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Disabled : public seat // Disabled derived seat class
{
private:
    void initName() override { m_Name = "Disabled"; };

public:
    // Constructor
    Disabled(std::map<std::string, int> &PriceMap) : seat(PriceMap)
    {
        initName();
        initPrice(m_Name);
    }; // seat subclass constructor
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////