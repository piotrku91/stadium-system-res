#include <iostream>

enum Op
{
    Success,
    Fail,
    Error
};

namespace Events
{
    const std::string Success = "[Success]";
    const std::string Fail = "[Fail] ";
    const std::string Error = "[Error]";
}

class log
{
private:
    void saveToFile();
    std::string getEventName(Op Event);
public:
    void addLog(Op LogEvent, std::string Operation);
};