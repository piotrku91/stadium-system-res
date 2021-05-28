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
    size_t m_Floor;

    // Map with Prices List
    std::map<std::string, int> ActualPrices{
        {"Standard", 370},
        {"Disabled", 250},
        {"VIP", 1000}};

    // Black list to implement

    // Person list to implement

    std::vector<TRow> wholeObject; // Seats list (m_LineSeats*m_RowSeats*m_Floor)

    // Private functions
    void buildVector();

public:
    // Public functions
    const std::vector<TRow> &getWholeObject() { return wholeObject; };
    char getSymbol(std::unique_ptr<seat> &item); // Return first char of seat object name.
    // Zero-based numbering getters (index 0 = index 0)
    const std::vector<std::unique_ptr<seat>> &getLine(size_t Row, size_t Floor) { return wholeObject[Floor][Row]; };       // Zero-based numbering getter (index 0 = index 0)
    const std::unique_ptr<seat>& getSeat(size_t Seat, size_t Row, size_t Floor) { return wholeObject[Floor][Row][Seat]; }; // Zero-based numbering getter (index 0 = index 0)
    const std::unique_ptr<seat>& getSeat(size_t X, size_t Y); 
    size_t getSeats() const { return m_LineSeats; };
    size_t getRows() const { return m_RowSeats; };
    size_t getFloors() const { return m_Floor; };
    size_t getCountOfReservedSeats(const std::shared_ptr<Person> &PersonPtr);
    size_t getIdByCoords(size_t Seat, size_t Row, size_t Floor){ return Seat+Row*m_LineSeats+Floor*m_RowSeats*m_LineSeats;};
    size_t getIdByCoords(size_t X, size_t Y) {return X+Y*m_LineSeats; };

    // Constructor
    stadium(size_t SeatsInLine, size_t RowsOfLines, size_t Floors) : m_LineSeats(SeatsInLine), m_RowSeats(RowsOfLines), m_Floor(Floors)
    {
        buildVector();

        // Create example guy
        ExampleGuy = std::make_shared<Person>("Janusz", "Laparoskop", "223300");
    };
};