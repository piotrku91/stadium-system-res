#pragma once
#include <map>
#include <vector>
#include "person.hpp"
#include "seat.hpp"
// Main stadium class file - Stadium object should be completely modular and prepared to move to another project or GUI
// This class is only demo version - need to be rebuild
using TRow = std::vector<std::vector<std::unique_ptr<seat>>>; // short notation of nested vectors
class stadium
{
    //Temporary public
public:
    std::shared_ptr<Person> ExampleGuy; // temporary guy for tests

private:
    // Private members
    size_t m_LineSeats;
    size_t m_RowSeats;
    size_t m_Floors;

    // Map with Prices List
    std::map<std::string, int> ActualPrices{
        {"Standard", 370},
        {"Disabled", 250},
        {"VIP", 1000}};

    // Black list to implement

    // Person list to implement

    std::vector<TRow> wholeObject; // Seats list (m_LineSeats*m_RowSeats*m_Floors)

    // Private functions
    void buildVector();

public:
    stadium(size_t t_SeatsInLine, size_t t_RowsOfLines, size_t t_Floors);

    // Public functions
    const std::vector<TRow>& getWholeObject();

    // Zero-based numbering getters (index 0 = index 0)
    const std::vector<std::unique_ptr<seat>>& getLine(size_t t_Row, size_t t_Floor);      // Zero-based numbering getter (index 0 = index 0)
    const std::unique_ptr<seat>& getSeat(size_t t_PosX, size_t t_PosY);                   // Zero-based numbering getter (index 0 = index 0)

    // Simple getters
    size_t getTotalSeats() const;
    size_t getTotalRows() const;
    size_t getTotalFloors() const;
    size_t getCountOfReservedSeats(const std::shared_ptr<Person>& t_pPerson) const;
    size_t getIdByCoords(size_t t_Seat, size_t t_Row, size_t t_Floor) const;
    size_t getIdByCoords(size_t t_PosX, size_t t_PosY) const;
};
