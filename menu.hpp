#include <iostream>
#include <memory>
#include <string>
#include "stadium.hpp"
#include "stdlib.h"

// This class is only demo version - need to be rebuild

class menu
{
private:
    int m_Operation; // Actual operation to switch.
    bool m_Exit; // If is true main loop it is going to break.
    std::shared_ptr<stadium> StadiumManager; // Keeps StadiumManager object smart pointer.
    
    bool isValid(int Input); // Checks is input from console is valid.

public: // Menu
    void operator()(); // Overloaded () operator
    
// Constructor
    menu(std::shared_ptr<stadium> &SM) : m_Operation{false},m_Exit{false}, StadiumManager(SM){};
};