#include "menu.hpp"

// Menu basic internal functions file

void menu::operator()()
    {
        Logger(Op::Success,"Program started...");
        while (!m_Exit)
        {
            if (system("clear")) {}; // Clear console
            reloadView(); // Show representation
            std::cout << "-----------------------------------------------" << std::endl;
            std::cout << "Wybierz operacje do wykonania: " << std::endl;
            // reloadMenu();
            std::cin >> m_Operation; // Getting input from user

    if (isValid(m_Operation)) {
            switch (m_Operation)
            {
            case 0: // Do nothing - wait for operations
            {
                break;
            };
            /* Implementation of main functions - Create declarations in header file, write definitions in menu_main_func.cpp 
            and put here in switch case instructions (for example menuExit and menuError)*/
            case 9: // Break the loop and program exit
            {
                menuExit(); 
                break;
            }
            default: // Input value number is not implemented.
            {
                menuError();
                break;
            };
            };
            }
        };
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool menu::isValid(int Input)
{
Input = Input; // Just for pass compilation.
// Needs to be implemented. For now is always true.
return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::reloadView()
{
    std::cout << " ***** SYSTEM REZERWACJI MIEJSC STADIONOWYCH :) ***** FOR TRAINING " << std::endl;
    std::cout << std::endl;
    std::cout << "REPREZENTACJA GRAFICZNA MIEJSC :" << std::endl;
    std::cout << std::endl;

    // Simple column counter
    for (size_t i = 1; i <= StadiumManager->getLine().size(); i++)
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
    for (auto &OneSit : StadiumManager->getLine())
    {
        std::cout << "[" << StadiumManager->getSymbol(OneSit) << "] ";
    };
    std::cout << "\n\n\n";
}