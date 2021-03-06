#include "menu.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
menu::menu(std::shared_ptr<stadium> &t_pStadiumManager) : m_Exit(false), m_pStadiumManager(t_pStadiumManager) {}
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
        try
        {
            m_MapCommands.at(m_CommandArgs[0])();
        }
        catch (...)
        {
            // Invalid input handler
            m_DebugMsg << "Invalid input -> ";
            for (size_t i{0}; i < m_CommandArgs.size(); ++i)
            {
                if (i != 0)
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
    if (system("clear"))
    {
    } // Clear console

    if (m_Debug)
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
    for (size_t i = 1; i <= m_pStadiumManager->getTotalSeats(); i++)
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
                //temporary solution of representation busy and free seat
                char So = '[';
                char Sc = ']';
                if (Seat->isBusy())
                {
                    So = Sc = ':';
                }

                std::cout << std::setw(1) << So << Seat->getSymbol() << Sc << " ";
            };
            std::cout << std::endl;
        };

        std::cout << std::endl;
    };
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::tokenize(const std::string &t_UserCommand, const char t_Delim, std::vector<std::string> &t_Args)
{
    size_t start;
    size_t end{0};

    while ((start = t_UserCommand.find_first_not_of(t_Delim, end)) != std::string::npos)
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
    if (seat < this->m_pStadiumManager->getTotalSeats() && row < this->m_pStadiumManager->getTotalRows())
    {
        this->m_pStadiumManager->getSeat(seat, row)->reserveSeat(this->m_pStadiumManager->ExampleGuy);
        m_DebugMsg << "Seat: " << seat + 1 << ", row: " << row + 1
                   << " reserved succesfully by " << this->m_pStadiumManager->ExampleGuy->getFullName();
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
                     << " zarezerwowa?? "
                     << this->m_pStadiumManager->getCountOfReservedSeats(this->m_pStadiumManager->ExampleGuy)
                     << " miejsc.";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::showCoords()
{
    size_t Id = std::stoull(this->m_CommandArgs.at(1));

    if (Id < seat::Counter)
    {
        this->m_DebugMsg << " Wsp????rz??dne siedzenia o ID " + std::to_string(Id) + " to "
        << this->m_pStadiumManager->coordsToStr(this->m_pStadiumManager->getCoordsById(Id));
    }
    else
    {
        m_DebugMsg << "Invalid Seat Id number.";
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::exit()
{
    this->m_Exit = true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
