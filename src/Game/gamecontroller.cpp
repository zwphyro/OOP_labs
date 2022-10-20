#include "gamecontroller.h"

#include "./../Logging/filelogger.h"
#include "./../Logging/consolelogger.h"
#include "./../Logging/logpermissions.h"
#include "./../Logging/loglevel.h"
#include "mainloop.h"

GameController::GameController()
{
    _permissions = new LogPermissions;
    _console_logger = new ConsoleLogger;
    _file_logger = new FileLogger;
    _observers = new ObserverSet;

    _console_logger->setLogPermissions(_permissions);
    _file_logger->setLogPermissions(_permissions);

    _observers->insert(_console_logger);
    _observers->insert(_file_logger);
}

GameController::~GameController()
{
    delete _console_logger;
    delete _file_logger;
    delete _permissions;
    delete _observers;
}

int GameController::exec()
{

    _permissions->setPermission(LogLevels::EXCEPTIONS, true);
    _permissions->setPermission(LogLevels::GAME_ENTITIES, true);
    _permissions->setPermission(LogLevels::GAME_STATES, true);

    _file_logger->changeState(true);

    MainLoop *game_session = new MainLoop(_observers);

    int out = game_session->exec();

    delete game_session;

    return out;
}
