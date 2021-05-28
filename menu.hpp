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
    log m_Logger;                                   // Log object
    std::string m_UserCommand;                      // User command
    bool m_Exit;                                    // The mighty main loop breaker!
    std::shared_ptr<stadium> m_pStadiumManager;     // Keeps StadiumManager object smart pointer.

    // m_Debug switches on and off additional debug menu
    bool m_Debug {true};                            // Switch it to false when releasing for production
    std::stringstream m_DebugMsg {""};

    // Menu basic internal functions
    std::vector<std::string> m_CommandArgs;         // User command divided into arguments
    void tokenize(const std::string& t_UserCommand, const char t_Delim, std::vector<std::string>& t_Args);
    void reserveSeat();
    void checkReserved();
    void exit();
    void menuError(std::string t_Message);

    // Map of commands and relevant lambdas
    std::map<std::string, std::function<void()>> m_MapCommands
    {
        {"exit", [this](){ this->exit(); }},
        {"reserved", [this](){ this->checkReserved(); }},
        {"rezerwuj", [this](){ this->reserveSeat(); }} // seat row floor
    };

public:
    menu(std::shared_ptr<stadium>& t_pStadiumManager);

    // Menu basic internal functions
    void run();                                     // Entry point
    void mainLoop();
    void reloadView();                              // Shows graphic representation (prototype - needs to be rebuilded)

    //  Menu managing functions
    void menuExit();
};
