#include "optionsmodel.h"
#include "optionsparameters.h"

OptionsModel::OptionsModel(OptionsParameters *parameters) : _parameters(parameters)
{
}

void OptionsModel::setOptionsParameters(OptionsParameters *parameters)
{
    _parameters = parameters;
}

void OptionsModel::selectNextOption()
{
    _parameters->getCurrentOption() = (_parameters->getCurrentOption() + 1) % OPTIONS_PARAMETERS_COUNT;
    update();
}

void OptionsModel::selectPreviousOption()
{
    _parameters->getCurrentOption() = (_parameters->getCurrentOption() + OPTIONS_PARAMETERS_COUNT - 1) % OPTIONS_PARAMETERS_COUNT;
    update();
}

int OptionsModel::processOption(int state)
{
    if (state == 0 && _parameters->getCurrentOption() == OptionsParameters::QUIT)
    {
        update();
        return ReturnValue::QUIT;
    }

    if (_parameters->getCurrentOption() == OptionsParameters::WIDTH)
    {
        if (state > 0)
            _parameters->getFieldWidth() = 5 + (_parameters->getFieldWidth() - 5 + 95 + 1) % 95;
        else if (state < 0)
            _parameters->getFieldWidth() = 5 + (_parameters->getFieldWidth() - 5 + 95 - 1) % 95;
    }
    else if (_parameters->getCurrentOption() == OptionsParameters::HEIGHT)
    {
        if (state > 0)
            _parameters->getFieldHeight() = 5 + (_parameters->getFieldHeight() - 5 + 95 + 1) % 95;
        else if (state < 0)
            _parameters->getFieldHeight() = 5 + (_parameters->getFieldHeight() - 5 + 95 - 1) % 95;
    }
    else if (_parameters->getCurrentOption() == OptionsParameters::CONSOLE)
    {
        _parameters->getConsoleLogState() = !_parameters->getConsoleLogState();
        _parameters->getEntitiesLogLevelState() = _parameters->getEntitiesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
        _parameters->getGameStatesLogLevelState() = _parameters->getGameStatesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
        _parameters->getExceptionsLogLevelState() = _parameters->getExceptionsLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    }
    else if (_parameters->getCurrentOption() == OptionsParameters::FILE)
    {
        _parameters->getFileLogState() = !_parameters->getFileLogState();
        _parameters->getEntitiesLogLevelState() = _parameters->getEntitiesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
        _parameters->getGameStatesLogLevelState() = _parameters->getGameStatesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
        _parameters->getExceptionsLogLevelState() = _parameters->getExceptionsLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    }
    else if (_parameters->getCurrentOption() == OptionsParameters::ENTITIES)
    {
        _parameters->getEntitiesLogLevelState() = !_parameters->getEntitiesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    }
    else if (_parameters->getCurrentOption() == OptionsParameters::GAME_STATES)
    {
        _parameters->getGameStatesLogLevelState() = !_parameters->getGameStatesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    }
    else if (_parameters->getCurrentOption() == OptionsParameters::EXCEPTIONS)
    {
        _parameters->getExceptionsLogLevelState() = !_parameters->getExceptionsLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    }

    update();
    return ReturnValue::CONTINUE;
}
