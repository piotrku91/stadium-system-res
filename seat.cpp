#include "seat.hpp"

void seat::initPrice(std::string& byName)
{
    m_Price = Prices[byName];
}

bool seat::reserveSeat(const std::shared_ptr<Person>& PersonPtr)
{
    TicketOwner=PersonPtr;
    m_Name = "R";
    return true; // pass for compile - to rebuild
}