#ifndef LOGPERMISSIONS_H
#define LOGPERMISSIONS_H

#include <map>

typedef std::map<const int, bool> PermissionsMap;

class LogPermissions
{
public:
    LogPermissions();
    bool getPermission(int log_level);
    void setPermission(int log_level, bool state);

private:
    PermissionsMap _permissions;
};

#endif
