#include "optionsparameters.h"

OptionsParameters::OptionsParameters()
{
    _selected_option = WIDTH;
    _field_width = 5;
    _field_height = 5;
    _console_log_state = false;
    _file_log_state = false;
    _game_entities_log_level_state = false;
    _game_states_log_level_state = false;
    _exceptions_log_level_state = false;
}

int OptionsParameters::getCurrentOption() const
{
    return _selected_option;
}

int &OptionsParameters::getCurrentOption()
{
    return _selected_option;
}

int OptionsParameters::getFieldWidth() const
{
    return _field_width;
}

int &OptionsParameters::getFieldWidth()
{
    return _field_width;
}

int OptionsParameters::getFieldHeight() const
{
    return _field_height;
}

int &OptionsParameters::getFieldHeight()
{
    return _field_height;
}

bool OptionsParameters::getConsoleLogState() const
{
    return _console_log_state;
}

bool &OptionsParameters::getConsoleLogState()
{
    return _console_log_state;
}

bool OptionsParameters::getFileLogState() const
{
    return _file_log_state;
}

bool &OptionsParameters::getFileLogState()
{
    return _file_log_state;
}

bool OptionsParameters::getEntitiesLogLevelState() const
{
    return _game_entities_log_level_state;
}

bool &OptionsParameters::getEntitiesLogLevelState()
{
    return _game_entities_log_level_state;
}

bool OptionsParameters::getGameStatesLogLevelState() const
{
    return _game_states_log_level_state;
}

bool &OptionsParameters::getGameStatesLogLevelState()
{
    return _game_states_log_level_state;
}

bool OptionsParameters::getExceptionsLogLevelState() const
{
    return _exceptions_log_level_state;
}

bool &OptionsParameters::getExceptionsLogLevelState()
{
    return _exceptions_log_level_state;
}
