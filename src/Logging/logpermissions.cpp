#include "logpermissions.h"
#include "loglevel.h"

LogPermissions::LogPermissions()
{
    _permissions[LogLevels::UNDEFINED] = true;
    _permissions[LogLevels::GAME_ENTITIES] = false;
    _permissions[LogLevels::GAME_STATES] = false;
    _permissions[LogLevels::EXCEPTIONS] = false;
}

bool LogPermissions::getPermission(LogLevels log_level)
{
    return true;
}

void LogPermissions::setPermission(LogLevels log_level, bool state)
{
    _permissions[log_level] = state;
}
