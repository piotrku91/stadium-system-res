#include "menu.hpp"

// Menu managing functions file
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::menuExit()
{
    m_Exit = true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu::menuError(std::string Message)
{
    std::cout << Message << std::endl;
    m_Operation = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////