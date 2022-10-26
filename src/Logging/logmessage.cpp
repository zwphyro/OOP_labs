#include "logmessage.h"
#include "loglevel.h"
#include <map>
#include <iostream>

LogMessage::LogMessage(int log_level = 0, std::string log_info = "") : _log_level(log_level), _log_info(log_info)
{
}

int LogMessage::getLogLevel()
{
    return _log_level;
}

std::ostream &operator<<(std::ostream &out, const LogMessage &obj)
{
    std::map<const int, std::string> log_tags{
        {LogLevels::UNDEFINED, "UNDEFINED"},
        {LogLevels::GAME_ENTITIES, "GAME ENTITIES"},
        {LogLevels::GAME_STATES, "GAME STATES"},
        {LogLevels::EXCEPTIONS, "EXCEPTIONS"}};

    std::string prefix;

    if (obj._log_level > LOG_LEVELS_COUNT || obj._log_level < 0)
        prefix = LogLevels::UNDEFINED;
    else
        prefix = log_tags[obj._log_level];

    out << prefix;
    out << ": " << obj._log_info << '\n';

    return out;
}
