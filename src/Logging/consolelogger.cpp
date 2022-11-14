#include "consolelogger.h"
#include "logmessage.h"
#include "logpermissions.h"
#include <ncurses.h>

ConsoleLogger::~ConsoleLogger()
{
    std::cout << std::flush;
}

void ConsoleLogger::notify(LogMessage message)
{
    if (!_permissions)
        return;
    if (_state && _permissions->getPermission(message.getLogLevel()))
    {
        endwin();
        std::cout << message;
        initscr();
    }
}
