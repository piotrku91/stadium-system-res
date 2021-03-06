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
    std::map<std::string, size_t> ActualPrices;

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
    const std::unique_ptr<seat>& getSeat(size_t t_Seat, size_t t_Row, size_t t_Floor); // Zero-based numbering getter (index 0 = index 0)
    const std::unique_ptr<seat>& getSeat(size_t t_PosX, size_t t_PosY);                   // Zero-based numbering getter (index 0 = index 0)
    const std::unique_ptr<seat>& getSeat(size_t t_Id);

    // Simple getters
    size_t getTotalSeats() const;
    size_t getTotalRows() const;
    size_t getTotalFloors() const;
    size_t getCountOfReservedSeats(const std::shared_ptr<Person>& t_pPerson) const;
    size_t getIdByCoords(size_t t_Seat, size_t t_Row, size_t t_Floor) const;
    size_t getIdByCoords(size_t t_PosX, size_t t_PosY) const;
    std::pair<size_t, size_t> getCoordsById(size_t t_Id) const;
    std::string coordsToStr(std::pair<size_t, size_t> Coords);
    std::string coordsToStr(size_t t_PosX, size_t t_PosY); // Returns string of X, Y (incremented by 1)

    // Files
    bool loadPatternsToMap(const std::string &t_Filename, std::map<size_t, std::string> &t_Content); // Read patterns of type seats from file
    bool loadPricesToMap(const std::string &t_Filename, std::map<std::string, size_t> &t_Content); // Read actually prices from file

};
