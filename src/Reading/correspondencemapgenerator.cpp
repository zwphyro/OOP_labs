#include "correspondencemapgenerator.h"
#include <regex>
#include <iostream>
#include <fstream>
#include <cctype>

#include <ncurses.h>

CorrespondenceMapGenerator::CorrespondenceMapGenerator()
{
    _default_controls[Commands::MOVE_UP] = 259;
    _default_controls[Commands::MOVE_DOWN] = 258;
    _default_controls[Commands::MOVE_LEFT] = 260;
    _default_controls[Commands::MOVE_RIGHT] = 261;
    _default_controls[Commands::SHOOT] = ' ';
    _default_controls[Commands::QUIT] = 27;

    using namespace std::string_literals;
    _string_to_commands["MOVE UP"s] = Commands::MOVE_UP;
    _string_to_commands["MOVE DOWN"s] = Commands::MOVE_DOWN;
    _string_to_commands["MOVE LEFT"s] = Commands::MOVE_LEFT;
    _string_to_commands["MOVE RIGHT"s] = Commands::MOVE_RIGHT;
    _string_to_commands["SHOOT"s] = Commands::SHOOT;
    _string_to_commands["QUIT"s] = Commands::QUIT;

    processConfig();
}

std::map<int, Commands> &CorrespondenceMapGenerator::getCorrespondenceMap()
{
    return _correspondence_map;
}

void CorrespondenceMapGenerator::processConfig()
{
    std::ifstream config;
    config.open("config.txt");

    if (!config.is_open())
    {
        completeMap();
        return;
    }

    std::string processing_string;
    std::cmatch match_result;
    std::regex regular_expression("(\\[)"
                                  "(\\d{1,3}|[^0-9])"
                                  "(\\]\\s+)"
                                  "(MOVE UP|MOVE DOWN|MOVE LEFT|MOVE RIGHT|SHOOT|QUIT)");

    int key;
    Commands command;

    while (!config.eof())
    {
        std::getline(config, processing_string);
        if (std::regex_match(processing_string.c_str(), match_result, regular_expression))
        {
            if (isdigit(match_result[2].str()[0]))
                key = std::stoul(match_result[2]);
            else
                key = match_result[2].str()[0];
            command = _string_to_commands[match_result[4]];
            processPair(key, command);
        }
    }
    config.close();
    completeMap();
}

void CorrespondenceMapGenerator::processPair(int key, Commands command)
{
    if (_default_controls[command] == key)
    {
        if (_registred_commands.find(command) != _registred_commands.end())
        {
            for (auto element : _correspondence_map)
                if (element.second == command)
                {
                    _correspondence_map.erase(element.first);
                    break;
                }
        }

        if (_correspondence_map.find(key) != _correspondence_map.end())
            processPair(_default_controls[_correspondence_map[key]], _correspondence_map[key]);

        _correspondence_map[key] = command;
        _registred_commands.insert(command);
        return;
    }

    if (_correspondence_map.find(key) != _correspondence_map.end() || _undefined_keys.find(key) != _undefined_keys.end())
    {
        processPair(_default_controls[command], command);
        processPair(_default_controls[_correspondence_map[key]], _correspondence_map[key]);
        _undefined_keys.insert(key);
        return;
    }

    if (_registred_commands.find(command) != _registred_commands.end())
    {
        processPair(_default_controls[command], command);
        return;
    }

    _correspondence_map[key] = command;
    _registred_commands.insert(command);
}

void CorrespondenceMapGenerator::completeMap()
{
    for (auto element : _default_controls)
    {
        if (_registred_commands.find(element.first) == _registred_commands.end())
        {
            _correspondence_map[element.second] = element.first;
        }
    }
}
