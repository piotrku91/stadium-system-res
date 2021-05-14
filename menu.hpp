#include <iostream>
#include <memory>
#include "stadium.hpp"

class menu
{
private:
    int m_lastOperation;
    bool m_Exit;
    std::shared_ptr<stadium> StadiumManager;

public: // Menu
    void operator()()
    {
        while (!m_Exit)
        {

            std::cout << "Wybierz operacje do wykonania: " << std::endl;
            std::cin >> m_lastOperation;

            switch (m_lastOperation)
            {
            case 1:
            {
                break;
            }
            default:
            {
                std::cout << "error" << std::endl;
            };
            }
        };
    };

    menu(std::shared_ptr<stadium> &SM) : m_Exit(false), StadiumManager(SM){};
};