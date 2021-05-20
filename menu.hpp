#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include "stadium.hpp"
#include "stdlib.h"
#include "log.hpp"


// This class is only demo version - need to be rebuild

class menu
{
private:
    log Logger;                               // Log object
    int m_Operation;                         // Actual operation to switch.
    bool m_Exit;                             // If is true main loop it is going to break.
    std::shared_ptr<stadium> StadiumManager; // Keeps StadiumManager object smart pointer.

    // Menu basic internal functions
    bool isValid(int Input); // Checks is input from console is valid. (prototype - needs to be rebuilded)

public:
    // Menu basic internal functions
    void operator()(); // Overloaded () operator
    void reloadView(); // Shows graphic representation (prototype - needs to be rebuilded)
    void reloadMenu(); // Shows menu entries (prototype - needs to be implemented)
    //  Menu managing functions
    void menuExit();
    void menuError(std::string Message = "error");
    // And more to implement

    // Constructor
    menu(std::shared_ptr<stadium> &SM) : m_Operation{false}, m_Exit{false}, StadiumManager(SM){};
};