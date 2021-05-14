#pragma once
#include "person.hpp"
#include "seat.hpp"
#include <map>

class stadium
{
private:
    size_t m_LineSeats;
    size_t m_RowSeats;
    size_t m_Floor;

    std::map<std::string, int> prices;

    // Person list

    // Seats list (m_LineSeats*m_RowSeats*m_Floor)

public:
    void reloadView();
    Standard Nowy{prices};

    stadium(size_t SeatsInLine, size_t RowsOfLines, size_t Floors) : m_LineSeats(SeatsInLine), m_RowSeats(RowsOfLines), m_Floor(Floors){};
};