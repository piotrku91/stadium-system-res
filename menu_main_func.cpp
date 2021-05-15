#include "menu.hpp"

// Menu managing functions file
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::menuExit()
{
    Logger.addLog(Op::Success, "Program finished the work.");
    m_Exit = true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::menuError(std::string Message)
{
    std::cout << Message << std::endl;
    Logger.addLog(Op::Error, Message);
    m_Operation = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
