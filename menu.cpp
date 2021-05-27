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
        std::getline(std::cin, m_Command);
        tokenize(m_Command, ' ', m_CommandArgs);
        try { m_Commands.at(m_CommandArgs[0])(); }
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
            Logger(Op::Error, m_DebugMsg.str());
        }
    };
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::reloadView()
{
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

void menu::tokenize(const std::string& command_sentence, const char delim, std::vector<std::string>& args)
{
    size_t start;
    size_t end {0};

    while((start = command_sentence.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = command_sentence.find(delim, start);
        args.push_back(command_sentence.substr(start, end - start));
    }
}

void menu::reserveSeat()
{
    size_t seat = std::stoull(this->m_CommandArgs.at(1)) - 1;
    size_t row = std::stoull(this->m_CommandArgs.at(2)) - 1;
    size_t floor = std::stoull(this->m_CommandArgs.at(3)) - 1;
    if(seat < this->StadiumManager->getSeatsInLineAmount() && row < this->StadiumManager->getRows() && floor < this->StadiumManager->getFloors())
    {
        this->StadiumManager->getSeat(seat, row, floor)->reserveSeat(this->StadiumManager->ExampleGuy);
        m_DebugMsg << "Seat: " << seat + 1 << ", row: " << row + 1 << ", floor: " << floor + 1
            << " reserved succesfully by " << this->StadiumManager->ExampleGuy->getFullName();
    }
    else
    {
        m_DebugMsg << "Seat not reserved due to invalid arguments either in seat, row or floor";
    }
}

void menu::checkReserved()
{
    this->m_DebugMsg << this->StadiumManager->ExampleGuy->getFullName() << " zarezerwował "
        << this->StadiumManager->getCountOfReservedSeats(this->StadiumManager->ExampleGuy) << " miejsc.";
}

void menu::exit()
{
    this->m_Exit = true;
}