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
            { //TODO: implement creation of proper object in right places
                // if (i<10) { Line.emplace_back(seat::createSeat<Standard>(ActualPrices)); } else { Line.emplace_back(seat::createSeat<VIP>(ActualPrices)); }; // test
                Line.push_back(seat::createSeat<Standard>(ActualPrices));
            };
            Row.push_back(std::move(Line));
        };
        wholeObject.push_back(std::move(Row));
    };
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t stadium::getCountOfReservedSeats(const std::shared_ptr<Person> &PersonPtr)
{
    if (PersonPtr)
    {
        return PersonPtr.use_count() - 1;
    };
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const std::unique_ptr<seat> &stadium::getSeat(size_t X, size_t Y)
{
    size_t FloorCount = Y * m_LineSeats / (m_LineSeats * m_RowSeats);
    size_t RowCount = Y;
    if ((Y) > m_RowSeats)
        RowCount = RowCount - ((FloorCount)*m_RowSeats);
    return wholeObject[FloorCount][RowCount][X];
}