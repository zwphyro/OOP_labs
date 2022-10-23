#ifndef OPTIONSPARAMETERS_H
#define OPTIONSPARAMETERS_H

#define OPTIONS_PARAMETERS_COUNT 8

class OptionsParameters
{
public:
    OptionsParameters();

    int getCurrentOption() const;
    int &getCurrentOption();

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
    int _field_width;
    int _field_height;
    bool _console_log_state;
    bool _file_log_state;
    bool _game_entities_log_level_state;
    bool _game_states_log_level_state;
    bool _exceptions_log_level_state;
};

#endif
