#include "stadium.hpp"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stadium::reloadView()
{
    std::cout << " ***** SYSTEM REZERWACJI MIEJSC STADIONOWYCH :) ***** FOR TRAINING " << std::endl;
    std::cout << std::endl;
    std::cout << "REPREZENTACJA GRAFICZNA MIEJSC :" << std::endl;
    std::cout << std::endl;

// Simple column counter
    for (size_t i = 1; i <= Line.size(); i++)  
    {
        if (i < 10)
        {
            std::cout << " " << i << "  ";
        }
        else
        {
            std::cout << " " << i << " ";
        };
    };
    std::cout << std::endl;

// Access to element by range-based loop
    for (auto &OneSit : getLine())
    {
        std::cout << "[" << getSymbol(OneSit) << "] ";
    };
    std::cout << "\n\n\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char stadium::getSymbol(std::unique_ptr<seat> &item)
{
    return item->getName()[0];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////