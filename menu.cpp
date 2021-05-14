#include "menu.hpp"

// Menu basic internal functions file

void menu::operator()()
    {
        while (!m_Exit)
        {
            if (system("clear")) {}; // Clear console
            StadiumManager->reloadView(); // Show representation
            std::cout << "-----------------------------------------------" << std::endl;
            std::cout << "Wybierz operacje do wykonania: " << std::endl;
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
            case 8: // Break the loop and program exit
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
// Need to be implemented. For now is always true.
return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////