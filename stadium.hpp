#pragma once
#include <map>
#include <vector>
#include "person.hpp"
#include "seat.hpp"
// Main stadium class file - Stadium object should be completely modular and prepared to move to another project or GUI
// This class is only demo version - need to be rebuild
class stadium
{
private:
    size_t m_LineSeats;
    size_t m_RowSeats;
    size_t m_Floor;

    // Map with Prices List
    std::map<std::string, int> Prices{
        {"Standard", 370},
        {"Disabled", 250},
        {"VIP", 1000}};

    // Black list to implement

    // Person list to implement

    // Seats list (m_LineSeats*m_RowSeats*m_Floor) to implement as 3 vectors (prototype - needs to be implemented)
    std::vector<std::unique_ptr<seat>> Line; // One for example.

    void temporary_fill_function(int size) // fill function just for debug and example (prototype - needs to be rebuilded and renamed)
    {
        for (int i = 0; i < size; i++)
        {
            Line.emplace_back(std::make_unique<Standard>(Prices));
        };
    };

public:
    char getSymbol(std::unique_ptr<seat> &item); // Return first char of seat object name.
    std::vector<std::unique_ptr<seat>> &getLine() { return Line; };

    // Constructor
    stadium(size_t SeatsInLine, size_t RowsOfLines, size_t Floors) : m_LineSeats(SeatsInLine), m_RowSeats(RowsOfLines), m_Floor(Floors)
    {
        temporary_fill_function(SeatsInLine);
    };
};