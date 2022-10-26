#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

class OptionsParameters;
class ConsoleLogger;
class FileLogger;
class LogPermissions;
class Observer;

#include <vector>

class LogSystem
{
public:
    LogSystem(const OptionsParameters *parameters = nullptr);
    ~LogSystem();
    void setParameters(const OptionsParameters *parameters);
    void updateParameters();
    std::vector<Observer *> *getObservers();

private:
    const OptionsParameters *_parameters;
    ConsoleLogger *_console_logger;
    FileLogger *_file_logger;
    LogPermissions *_permissions;
    std::vector<Observer *> *_observers;
};

#endif
