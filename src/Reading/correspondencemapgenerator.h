#ifndef CORRESPONDENCEMAPGENERATOR_H
#define CORRESPONDENCEMAPGENERATOR_H

#include "commands.h"
#include <map>
#include <set>
#include <string>

class CorrespondenceMapGenerator
{
public:
    CorrespondenceMapGenerator();
    std::map<int, Commands>& getCorrespondenceMap();
private:
    std::map<int, Commands> _correspondence_map;
    std::map<Commands, int> _default_controls;
    std::map<std::string, Commands> _string_to_commands;
    std::set<Commands> _registred_commands;
    std::set<int> _undefined_keys;
    void processConfig();
    void processPair(int key, Commands command);
    void completeMap();
};

#endif
