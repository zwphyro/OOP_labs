#ifndef CONSOLEADAPTER_H
#define CONSOLEADAPTER_H

#include "./commands.h"
#include "./commandreader.h"
#include <map>
class ConsoleReader;
class CorrespondenceMapGenerator;

class ConsoleAdapter : public CommandReader
{
public:
    ConsoleAdapter();
    ~ConsoleAdapter();
    Commands getCommand();
private: 
    ConsoleReader *_console_reader;
    std::map<int, Commands> _correspondence_map;
    CorrespondenceMapGenerator *_correspondence_map_generator;
};

#endif
