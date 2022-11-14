#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <string>
#include "loglevel.h"
#include <map>

class LogMessage
{
public:
    LogMessage(LogLevels log_level, std::string log_info);
    LogLevels getLogLevel();
    friend std::ostream &operator<<(std::ostream &out, const LogMessage &obj);

private:
    static std::map<const int, std::string> _log_tags;
    LogLevels _log_level;
    std::string _log_info;
};

#endif
