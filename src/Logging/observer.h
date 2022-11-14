#ifndef OBSERVER_H
#define OBSERVER_H

class LogMessage;
class LogPermissions;

class Observer
{
public:
    Observer(LogPermissions *permissions = nullptr);
    virtual ~Observer() = 0;
    void setLogPermissions(LogPermissions *permissions);
    void changeState(bool new_state);
    virtual void notify(LogMessage message) = 0;

protected:
    LogPermissions *_permissions;
    bool _state;
};

#endif
