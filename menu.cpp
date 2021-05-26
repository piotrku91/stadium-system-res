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
        std::getline(std::cin, m_Operation); // Getting input from user
        try { m_Commands.at(m_Operation)(); }
        catch (...)
        {
            // Invalid input handler
            m_DebugMsg = "Invalid input. Passed command: " + m_Operation;
            Logger(Op::Error, "Invalid input. Passed command: " + m_Operation); // Needs rebuilding when application expand to catch exception msgs
        }
    };
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::reloadView()
{
    if(m_Debug)
    {
        std::cout << "*** DEBUG MENU ***\n";
        std::cout << "Debug msg: " << m_DebugMsg << '\n';
        std::cout << "*** DEBUG MENU ***\n\n";
        m_DebugMsg = "";
    }
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