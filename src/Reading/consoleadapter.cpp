#include "consoleadapter.h"
#include "consolereader.h"
#include "correspondencemapgenerator.h"

#include <iostream>
#include <ncurses.h>

ConsoleAdapter::ConsoleAdapter()
{
    _correspondence_map_generator = new CorrespondenceMapGenerator;
    _correspondence_map = _correspondence_map_generator->getCorrespondenceMap();
    _console_reader = new ConsoleReader;
}

ConsoleAdapter::~ConsoleAdapter()
{
    delete _console_reader;
    delete _correspondence_map_generator;
}

Commands ConsoleAdapter::getCommand()
{
    int key = _console_reader->getPressedKey();
    if (_correspondence_map.find(key) == _correspondence_map.end())
        return Commands::UNKNOWN;
    return _correspondence_map[key];
}
