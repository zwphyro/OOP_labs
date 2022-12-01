#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include "./commands.h"

class CommandReader
{
public:
    virtual Commands getCommand() = 0;
};

#endif
