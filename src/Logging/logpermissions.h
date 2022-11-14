#ifndef LOGPERMISSIONS_H
#define LOGPERMISSIONS_H

#include <map>
#include "loglevel.h"

typedef std::map<const int, bool> PermissionsMap;

class LogPermissions
{
public:
    LogPermissions();
    bool getPermission(LogLevels log_level);
    void setPermission(LogLevels log_level, bool state);

private:
    PermissionsMap _permissions;
};

#endif
