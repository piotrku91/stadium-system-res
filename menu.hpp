#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <map>
#include <functional>
#include "stadium.hpp"
#include "stdlib.h"
#include "log.hpp"


// This class is only demo version - need to be rebuild

class menu
{
private:
    log Logger;                               // Log object
    std::string m_Command;                         // Actual operation to switch.
    bool m_Exit;                             // If is true main loop it is going to break.
    std::shared_ptr<stadium> StadiumManager; // Keeps StadiumManager object smart pointer.

    // m_Debug switches on and off additional debug menu
    bool m_Debug {true};                        // Switch it to false when releasing for production
    std::stringstream m_DebugMsg {""};

    // Menu basic internal functions
    std::vector<std::string> m_CommandArgs;
    void tokenize(const std::string& command_sentence, const char delim, std::vector<std::string>& args);

    // Map of commands and relevant lambdas
    // Methods must throw exceptions if there is a need to trigger invalid input handler
    std::map<std::string, std::function<void()>> m_Commands
    {
        {"idle", [](){ return; }},
        {"exit", [this](){ m_Exit = true; }}
    };

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
    menu(std::shared_ptr<stadium> &SM) : m_Exit{false}, StadiumManager(SM){};
};