#include "menu.hpp"



void menu::operator()()
    {
        while (!m_Exit)
        {
            system("clear"); // Clear console
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
            case 8: // Break the loop and program exit
            {
                m_Exit=true; 
                break;
            }
            default: // Input value number is not implemented.
            {
                std::cout << "error" << std::endl;
                m_Operation = 0;
                break;
            };
            };
            }
        };
    }

    bool menu::isValid(int Input)
{
Input = Input; // Just for pass compilation.
// Need to be implemented. For now is always true.
return true;
}