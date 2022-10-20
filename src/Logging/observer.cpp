#include "observer.h"

Observer::Observer(LogPermissions *permissions) : _permissions{permissions}, _state(false)
{
}

Observer::~Observer()
{
}

void Observer::setLogPermissions(LogPermissions *permissions)
{
    _permissions = permissions;
}

void Observer::changeState(bool new_state)
{
    _state = new_state;
}
