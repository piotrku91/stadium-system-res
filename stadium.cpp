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
                    Line.emplace_back(seat::createSeat<Standard>(ActualPrices));
                };
                Row.emplace_back(std::move(Line));
            };
            wholeObject.emplace_back(std::move(Row));
        };
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////