#ifndef OPTIONSPARAMETERS_H
#define OPTIONSPARAMETERS_H

#define OPTIONS_PARAMETERS_COUNT 9

class FieldGeneratorStrategy;

enum Generator
{
    MAZE,
    EXPONSE
};

#include <map>

class OptionsParameters
{
public:
    OptionsParameters();
    ~OptionsParameters();

    int getCurrentOption() const;
    int &getCurrentOption();

    FieldGeneratorStrategy *getFieldGenerator() const;
    Generator getFieldGenerator(int) const;
    Generator &getFieldGenerator();

    int getFieldWidth() const;
    int &getFieldWidth();

    int getFieldHeight() const;
    int &getFieldHeight();

    bool getConsoleLogState() const;
    bool &getConsoleLogState();

    bool getFileLogState() const;
    bool &getFileLogState();

    bool getEntitiesLogLevelState() const;
    bool &getEntitiesLogLevelState();

    bool getGameStatesLogLevelState() const;
    bool &getGameStatesLogLevelState();

    bool getExceptionsLogLevelState() const;
    bool &getExceptionsLogLevelState();

    enum
    {
        GENERATOR,
        WIDTH,
        HEIGHT,
        CONSOLE,
        FILE,
        ENTITIES,
        GAME_STATES,
        EXCEPTIONS,
        QUIT
    };

private:
    int _selected_option;
    Generator _field_generator;
    int _field_width;
    int _field_height;
    bool _console_log_state;
    bool _file_log_state;
    bool _game_entities_log_level_state;
    bool _game_states_log_level_state;
    bool _exceptions_log_level_state;

    std::map<Generator, FieldGeneratorStrategy *> _field_renerator_map;
};

#endif
