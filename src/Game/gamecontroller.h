#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class ConsoleLogger;
class FileLogger;
class LogPermissions;
#include <set>
class Observer;
typedef class std::set<Observer *> ObserverSet;

class GameController
{
public:
    GameController();
    ~GameController();
    int exec();

private:
    ConsoleLogger *_console_logger;
    FileLogger *_file_logger;
    LogPermissions *_permissions;
    ObserverSet *_observers;
};

#endif
