#include "menu.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
menu::menu(std::shared_ptr<stadium>& t_pStadiumManager) : m_Exit(false), m_pStadiumManager(t_pStadiumManager){}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::run()
{
    m_Logger(Op::Success, "Program started...");
    this->mainLoop();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::mainLoop()
{
    while (!m_Exit)
    {
        reloadView(); // Show representation
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Wybierz operacje do wykonania: " << std::endl;
        std::getline(std::cin, m_UserCommand);
        tokenize(m_UserCommand, ' ', m_CommandArgs);
        try { m_MapCommands.at(m_CommandArgs[0])(); }
        catch (...)
        {
            // Invalid input handler
            m_DebugMsg << "Invalid input -> ";
            for(size_t i {0}; i < m_CommandArgs.size(); ++i)
            {
                if(i != 0)
                {
                    m_DebugMsg << ", ";
                }
                m_DebugMsg << "arg[" << i << "]: \"" << m_CommandArgs[i] << "\"";
            }
            m_Logger(Op::Error, m_DebugMsg.str());
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::reloadView()
{
    system("clear"); // Clear console

    if(m_Debug)
    {
        std::cout << "*** DEBUG MENU ***\n";
        std::cout << "Debug msg: " << m_DebugMsg.str() << '\n';
        std::cout << "*** DEBUG MENU ***\n\n";
        m_DebugMsg.str("");
        m_CommandArgs.clear();
    }
    std::cout << " ***** SYSTEM REZERWACJI MIEJSC STADIONOWYCH :) ***** FOR TRAINING " << std::endl;
    std::cout << std::endl;
    std::cout << "REPREZENTACJA GRAFICZNA MIEJSC :" << std::endl;
    std::cout << std::endl;

    // Simple column counter
    std::cout << " X  ";
    for (size_t i = 1; i <= m_pStadiumManager->getTotalSeatsInLine(); i++)
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

    int LineCounter = 1; // Counter for next lines
    for (auto &StadiumRow : m_pStadiumManager->getWholeObject())
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::tokenize(const std::string& t_UserCommand, const char t_Delim, std::vector<std::string>& t_Args)
{
    size_t start;
    size_t end {0};

    while((start = t_UserCommand.find_first_not_of(t_Delim, end)) != std::string::npos)
    {
        end = t_UserCommand.find(t_Delim, start);
        t_Args.push_back(t_UserCommand.substr(start, end - start));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::reserveSeat()
{
    size_t seat = std::stoull(this->m_CommandArgs.at(1)) - 1;
    size_t row = std::stoull(this->m_CommandArgs.at(2)) - 1;
    size_t floor = std::stoull(this->m_CommandArgs.at(3)) - 1;
    if(seat < this->m_pStadiumManager->getTotalSeatsInLine() && row < this->m_pStadiumManager->getTotalRows() && floor < this->m_pStadiumManager->getTotalFloors())
    {
        this->m_pStadiumManager->getSeat(seat, row, floor)->reserveSeat(this->m_pStadiumManager->ExampleGuy);
        m_DebugMsg << "Seat: " << seat + 1 << ", row: " << row + 1
                   << ", floor: " << floor + 1 << " reserved succesfully by "
                   << this->m_pStadiumManager->ExampleGuy->getFullName();
    }
    else
    {
        m_DebugMsg << "Seat not reserved due to invalid arguments either in seat, row or floor";
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::checkReserved()
{
    this->m_DebugMsg << this->m_pStadiumManager->ExampleGuy->getFullName()
                     << " zarezerwował "
                     << this->m_pStadiumManager->getCountOfReservedSeats(this->m_pStadiumManager->ExampleGuy)
                     << " miejsc.";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::exit()
{
    this->m_Exit = true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
