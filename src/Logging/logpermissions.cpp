#include "logpermissions.h"
#include "loglevel.h"

LogPermissions::LogPermissions()
{
    _permissions[LogLevels::UNDEFINED] = true;
    _permissions[LogLevels::GAME_ENTITIES] = false;
    _permissions[LogLevels::GAME_STATES] = false;
    _permissions[LogLevels::EXCEPTIONS] = false;
}

bool LogPermissions::getPermission(int log_level)
{
    if (!(log_level > LOG_LEVELS_COUNT && log_level < 0))
        return _permissions[log_level];
    return true;
}

void LogPermissions::setPermission(int log_level, bool state)
{
    _permissions[log_level] = state;
}
