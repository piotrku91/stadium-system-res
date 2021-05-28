#include "stadium.hpp"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void stadium::buildVector() // build nested vectors (fill wholeObject member)
{
    for (size_t k = 0; k < m_Floor; k++)
    {
        TRow Row;
        for (size_t j = 0; j < m_RowSeats; j++)
        {
            std::vector<std::unique_ptr<seat>> Line;
            for (size_t i = 0; i < m_LineSeats; i++)
            {   //TODO: implement creation of proper object in right places 
                // if (i<10) { Line.emplace_back(seat::createSeat<Standard>(ActualPrices)); } else { Line.emplace_back(seat::createSeat<VIP>(ActualPrices)); }; // test
                Line.push_back(seat::createSeat<Standard>(ActualPrices));
            }
            Row.push_back(std::move(Line));
        }
        wholeObject.push_back(std::move(Row));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
stadium::stadium(size_t t_SeatsInLine, size_t t_RowsOfLines, size_t t_Floors)
    : m_LineSeats(t_SeatsInLine), m_RowSeats(t_RowsOfLines), m_Floor(t_Floors)
{
    buildVector();

    // Create example guy
    ExampleGuy = std::make_shared<Person>("Janusz", "Laparoskop", "223300");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
const std::vector<TRow>& stadium::getWholeObject()
{
    return this->wholeObject;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::vector<std::unique_ptr<seat>>& stadium::getLine(size_t t_Row, size_t t_Floor)
{
    // Zero-based numbering getter (index 0 = index 0)
    return this->wholeObject[t_Floor][t_Row];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::unique_ptr<seat>& stadium::getSeat(size_t t_Seat, size_t t_Row, size_t t_Floor)
{
    // Zero-based numbering getter (index 0 = index 0)
    return this->wholeObject[t_Floor][t_Row][t_Seat];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getTotalSeatsInLine() const
{
    return this->m_LineSeats;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getTotalRows() const
{
    return this->m_RowSeats;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getTotalFloors() const
{
    return this->m_Floor;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getCountOfReservedSeats(const std::shared_ptr<Person>& t_pPerson) const
{
     if(t_pPerson)
     {
         return t_pPerson.use_count() - 1;
     }
     return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
