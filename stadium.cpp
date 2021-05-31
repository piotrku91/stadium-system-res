#include "stadium.hpp"
#include <fstream>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stadium::buildVector() // build nested vectors (fill wholeObject member)
{
    std::map<size_t, std::string> Pattern;
    loadPatternsToMap("seats_pattern.txt", Pattern);

    for (size_t k = 0; k < m_Floors; k++)
    {
        TRow Row;
        for (size_t j = 0; j < m_RowSeats; j++)
        {
            std::vector<std::unique_ptr<seat>> Line;
            for (size_t i = 0; i < m_LineSeats; i++)
            {
                if (Pattern[getIdByCoords(i, j, k)] == "VIP")
                {
                    Line.push_back(seat::createSeat<VIP>(ActualPrices));
                }
                else if (Pattern[getIdByCoords(i, j, k)] == "Disabled")
                {
                    Line.push_back(seat::createSeat<Disabled>(ActualPrices));
                }
                else
                {
                    Line.push_back(seat::createSeat<Standard>(ActualPrices));
                };
            }
            Row.push_back(std::move(Line));
        }
        wholeObject.push_back(std::move(Row));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
stadium::stadium(size_t t_SeatsInLine, size_t t_RowsOfLines, size_t t_Floors)
    : m_LineSeats(t_SeatsInLine), m_RowSeats(t_RowsOfLines), m_Floors(t_Floors)
{
    loadPricesToMap("prices.txt",ActualPrices);
    buildVector();

    // Create example guy
    ExampleGuy = std::make_shared<Person>("Janusz", "Laparoskop", "223300");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::vector<TRow> &stadium::getWholeObject()
{
    return this->wholeObject;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::vector<std::unique_ptr<seat>> &stadium::getLine(size_t t_Row, size_t t_Floor)
{
    // Zero-based numbering getter (index 0 = index 0)
    return this->wholeObject[t_Floor][t_Row];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::unique_ptr<seat> &stadium::getSeat(size_t t_Seat, size_t t_Row, size_t t_Floor)
{
    return this->wholeObject[t_Floor][t_Row][t_Seat];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::unique_ptr<seat> &stadium::getSeat(size_t t_PosX, size_t t_PosY)
{
    size_t FloorCount = t_PosY * this->m_LineSeats / (this->m_LineSeats * this->m_RowSeats);
    size_t RowCount = t_PosY;
    if (t_PosY >= m_RowSeats)
    {
        RowCount = RowCount - ((FloorCount)*m_RowSeats);
    }
    return wholeObject[FloorCount][RowCount][t_PosX];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::unique_ptr<seat> &stadium::getSeat(size_t t_Id)
{
    return getSeat(getCoordsById(t_Id).first, getCoordsById(t_Id).second);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getTotalSeats() const
{
    return this->m_LineSeats;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getTotalRows() const
{
    return this->m_RowSeats * this->m_Floors;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getTotalFloors() const
{
    return this->m_Floors;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getCountOfReservedSeats(const std::shared_ptr<Person> &t_pPerson) const
{
    if (t_pPerson)
    {
        return t_pPerson.use_count() - 1;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getIdByCoords(size_t t_Seat, size_t t_Row, size_t t_Floor) const
{
    return (t_Seat + t_Row * this->m_LineSeats + t_Floor * this->m_RowSeats * this->m_LineSeats) + 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getIdByCoords(size_t t_PosX, size_t t_PosY) const
{
    return (t_PosX + t_PosY * this->m_LineSeats) + 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::pair<size_t, size_t> stadium::getCoordsById(size_t t_Id) const
{
    size_t crow = (t_Id - 1) / this->m_LineSeats;
    size_t cseat = ((t_Id - 1) - (crow) * this->m_LineSeats);

    return std::make_pair(cseat, crow);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string stadium::coordsToStr(std::pair<size_t, size_t> t_Coords)
{
    return coordsToStr(t_Coords.first, t_Coords.second);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string stadium::coordsToStr(size_t t_PosX, size_t t_PosY)
{
    return "X: " + std::to_string(t_PosX + 1) + " Y: " + std::to_string(t_PosY + 1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool stadium::loadPatternsToMap(const std::string &t_Filename, std::map<size_t, std::string> &t_Content)
{
    std::ifstream input(t_Filename.c_str());
    std::string linestr;
    if (!input)
        return false;
    while (std::getline(input, linestr))
    {
        if (linestr.size() > 0)
        {
            t_Content.insert({std::stoi(linestr.substr(0, linestr.find_first_of(" "))), linestr.substr(linestr.find_first_of(" ") + 1, linestr.length())});
        };
    };
    input.close();
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool stadium::loadPricesToMap(const std::string &t_Filename, std::map<std::string, size_t> &t_Content)
{
    std::ifstream input(t_Filename.c_str());
    std::string linestr;
    if (!input)
        return false;
    while (std::getline(input, linestr))
    {
        if (linestr.size() > 0)
        {
            t_Content.insert({linestr.substr(0, linestr.find_first_of(" ")), std::stoi(linestr.substr(linestr.find_first_of(" ") + 1, linestr.length()))});
        };
    };
    input.close();
    return true;
}