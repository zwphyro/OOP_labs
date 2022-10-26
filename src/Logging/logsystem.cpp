#include "logsystem.h"
#include "consolelogger.h"
#include "filelogger.h"
#include "logpermissions.h"
#include "loglevel.h"
#include "./../Interface/Options/optionsparameters.h"

LogSystem::LogSystem(const OptionsParameters *parameters)
{
    _parameters = parameters;
    _permissions = new LogPermissions;
    _console_logger = new ConsoleLogger;
    _file_logger = new FileLogger;
    _console_logger->setLogPermissions(_permissions);
    _file_logger->setLogPermissions(_permissions);

    _observers = new std::vector<Observer *>;
    _observers->push_back(_console_logger);
    _observers->push_back(_file_logger);

    updateParameters();
}

LogSystem::~LogSystem()
{
    delete _observers;
    delete _console_logger;
    delete _file_logger;
    delete _permissions;
}

void LogSystem::setParameters(const OptionsParameters *parameters)
{
    _parameters = parameters;
    updateParameters();
}

void LogSystem::updateParameters()
{
    if (_parameters == nullptr)
        return;
    _console_logger->changeState(_parameters->getConsoleLogState());
    _file_logger->changeState(_parameters->getFileLogState());
    _permissions->setPermission(LogLevels::EXCEPTIONS, _parameters->getExceptionsLogLevelState());
    _permissions->setPermission(LogLevels::GAME_ENTITIES, _parameters->getEntitiesLogLevelState());
    _permissions->setPermission(LogLevels::GAME_STATES, _parameters->getGameStatesLogLevelState());
}

std::vector<Observer *> *LogSystem::getObservers()
{
    return _observers;
}
