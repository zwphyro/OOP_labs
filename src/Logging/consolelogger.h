#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

class LogMessage;
#include <iostream>
#include "observer.h"

class ConsoleLogger : public Observer
{
public:
    ~ConsoleLogger();
    void notify(LogMessage message);
};

#endif
