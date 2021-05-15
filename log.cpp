#include "log.hpp"

void log::addLog(Op Event, const std::string& Operation)
{
    std::string LineToSave = getEventName(Event) + " " + Operation; // After implementation function saveToFile we can remove LineToSave variable :) 
    // saveToFile(LineToSave);
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