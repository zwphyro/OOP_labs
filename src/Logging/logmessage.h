#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <string>

class LogMessage
{
public:
    LogMessage(int log_level, std::string log_info);
    int getLogLevel();
    friend std::ostream &operator<<(std::ostream &out, const LogMessage &obj);

private:
    int _log_level;
    std::string _log_info;
};

#endif
