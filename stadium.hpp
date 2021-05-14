#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "person.hpp"
#include "seat.hpp"


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

    // Seats list (m_LineSeats*m_RowSeats*m_Floor) to implement as 3 vectors
    std::vector<std::unique_ptr<seat>> Line; // One for example.

    void temporary_fill_funtion(int size) // fill function just for debug and example
    {
        for (int i = 0; i < size; i++)
        {
            Line.emplace_back(std::make_unique<Standard>(Prices));
        };
    };

public:
    void reloadView();
    char getSymbol(std::unique_ptr<seat> &item); // Return first char of seat object name.
    std::vector<std::unique_ptr<seat>> &getLine() { return Line; };

    // Constructor
    stadium(size_t SeatsInLine, size_t RowsOfLines, size_t Floors) : m_LineSeats(SeatsInLine), m_RowSeats(RowsOfLines), m_Floor(Floors)
    {
        temporary_fill_funtion(SeatsInLine);
    };
};