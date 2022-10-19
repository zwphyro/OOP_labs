#include "logpermissions.h"
#include "loglevel.h"

LogPermissions::LogPermissions()
{
    _permissions[LogLevels::GAME_ENTITIES] = false;
    _permissions[LogLevels::GAME_STATES] = false;
    _permissions[LogLevels::EXCEPTIONS] = false;
}

bool LogPermissions::getPermission(int log_level)
{
    return _permissions[log_level];
}

void LogPermissions::setPermission(int log_level, bool state)
{
    _permissions[log_level] = state;
}
