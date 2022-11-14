#include "logmessage.h"
#include "loglevel.h"
#include <iostream>

std::map<const int, std::string> LogMessage::_log_tags{
    {LogLevels::UNDEFINED, "UNDEFINED"},
    {LogLevels::GAME_ENTITIES, "GAME ENTITIES"},
    {LogLevels::GAME_STATES, "GAME STATES"},
    {LogLevels::EXCEPTIONS, "EXCEPTIONS"}};

LogMessage::LogMessage(LogLevels log_level = LogLevels::UNDEFINED, std::string log_info = "") : _log_level(log_level), _log_info(log_info)
{
}

LogLevels LogMessage::getLogLevel()
{
    return _log_level;
}

std::ostream &operator<<(std::ostream &out, const LogMessage &obj)
{
    out << "[" << LogMessage::_log_tags[obj._log_level] << "] ";
    out << obj._log_info << '\n';

    return out;
}
