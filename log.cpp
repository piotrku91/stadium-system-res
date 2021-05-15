#include "log.hpp"

void log::addLog(Op Event, std::string Operation)
{
    Operation = getEventName(Event) + " " + Operation;
    // saveToFile(Operation);
}

std::string log::getEventName(Op Event)
{
    switch (Event)
    {
    case Success:
    {
        return Events::Success;
    };
    case Fail:
    {
        return Events::Fail;
    };
    case Error:
    {
        return Events::Error;
    };
    default: return Events::Error;
    }
}