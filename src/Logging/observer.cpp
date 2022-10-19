#include "observer.h"

Observer::Observer(LogPermissions *permissions) : _permissions{permissions}
{
}

Observer::~Observer()
{
}

void Observer::setLogPermissions(LogPermissions *permissions)
{
    _permissions = permissions;
}
