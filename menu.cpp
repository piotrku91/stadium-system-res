#include "menu.hpp"

// Menu basic internal functions file

void menu::operator()()
{
    Logger(Op::Success, "Program started...");
    while (!m_Exit)
    {
        if (system("clear"))
        {
        };            // Clear console
        reloadView(); // Show representation
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Wybierz operacje do wykonania: " << std::endl;
        // reloadMenu();
        std::cin >> m_Operation; // Getting input from user

        if (isValid(m_Operation))
        {
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
    std::cout << " X  ";
    for (size_t i = 1; i <= StadiumManager->getSeatsInLineAmount(); i++)
    {

        if (i < 10)
        {
            std::cout << std::setw(1) << " " << i << "  ";
        }
        else
        {
            std::cout << std::setw(1) << " " << i << " ";
        };
    };
    std::cout << std::endl;

    // TEST BY CHANGE SOMETHING AND CHECK IF COORDINATES ARE OK :)
    StadiumManager->getLine(1, 0)[0]->testName();
    StadiumManager->getSeat(1, 1, 0)->testName();
    StadiumManager->getSeatPlus(1, 1, 1)->testName();

    int LineCounter = 1; // Counter for next lines
    for (auto &StadiumRow : StadiumManager->getWholeObject())
    {

        for (auto &StadiumLine : StadiumRow)
        {
            // Simple line counter
            if (LineCounter < 10)
            {
                std::cout << " " << LineCounter++ << "  ";
            }
            else
            {
                std::cout << " " << LineCounter++ << " ";
            };

            for (auto &Seat : StadiumLine)
            {
                std::cout << std::setw(1) << "[" << Seat->getSymbol() << "] ";
            };
            std::cout << std::endl;
        };

        std::cout << std::endl;
    };
}