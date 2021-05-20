#include "seat.hpp"

void seat::initPrice(std::string& byName)
{
    m_Price = Prices[byName];
}