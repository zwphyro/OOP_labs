#include "optionsmodel.h"
#include "optionsparameters.h"

#define MIN_SIZE 5
#define MAX_SIZE 100

std::map<const int, std::function<void(OptionsModel &, int)>> OptionsModel::_performed_functions{
    {OptionsParameters::GENERATOR, &OptionsModel::changeGenerator},
    {OptionsParameters::WIDTH, &OptionsModel::changeWidth},
    {OptionsParameters::HEIGHT, &OptionsModel::changeHeight},
    {OptionsParameters::CONSOLE, &OptionsModel::changeConsoleLogState},
    {OptionsParameters::FILE, &OptionsModel::changeFileLogState},
    {OptionsParameters::ENTITIES, &OptionsModel::changeEntitiesLogLevelState},
    {OptionsParameters::GAME_STATES, &OptionsModel::changeGameLevelsLogLevelState},
    {OptionsParameters::EXCEPTIONS, &OptionsModel::changeExceptionsLogLevelState}};

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

    _performed_functions[_parameters->getCurrentOption()](*this, state);

    update();
    return ReturnValue::CONTINUE;
}

void OptionsModel::changeGenerator(int state)
{
    if (_parameters->getFieldGenerator() == Generator::MAZE)
        _parameters->getFieldGenerator() = Generator::EXPONSE;
    else
        _parameters->getFieldGenerator() = Generator::MAZE;
}

void OptionsModel::changeWidth(int state)
{
    if (state >= 0)
        _parameters->getFieldWidth() = MIN_SIZE + (_parameters->getFieldWidth() - MIN_SIZE + (MAX_SIZE - MIN_SIZE) + 1) % (MAX_SIZE - MIN_SIZE);
    else
        _parameters->getFieldWidth() = 5 + (_parameters->getFieldWidth() - MIN_SIZE + (MAX_SIZE - MIN_SIZE) - 1) % (MAX_SIZE - MIN_SIZE);
}

void OptionsModel::changeHeight(int state)
{
    if (state >= 0)
        _parameters->getFieldHeight() = 5 + (_parameters->getFieldHeight() - MIN_SIZE + (MAX_SIZE - MIN_SIZE) + 1) % (MAX_SIZE - MIN_SIZE);
    else
        _parameters->getFieldHeight() = 5 + (_parameters->getFieldHeight() - MIN_SIZE + (MAX_SIZE - MIN_SIZE) - 1) % (MAX_SIZE - MIN_SIZE);
}

void OptionsModel::changeConsoleLogState(int)
{
    _parameters->getConsoleLogState() = !_parameters->getConsoleLogState();
    updateLogLevels();
}

void OptionsModel::changeFileLogState(int)
{
    _parameters->getFileLogState() = !_parameters->getFileLogState();
    updateLogLevels();
}

void OptionsModel::changeEntitiesLogLevelState(int)
{
    _parameters->getEntitiesLogLevelState() = !_parameters->getEntitiesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
}

void OptionsModel::changeGameLevelsLogLevelState(int)
{
    _parameters->getGameStatesLogLevelState() = !_parameters->getGameStatesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
}

void OptionsModel::changeExceptionsLogLevelState(int)
{
    _parameters->getExceptionsLogLevelState() = !_parameters->getExceptionsLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
}

void OptionsModel::updateLogLevels()
{
    _parameters->getEntitiesLogLevelState() = _parameters->getEntitiesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    _parameters->getGameStatesLogLevelState() = _parameters->getGameStatesLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
    _parameters->getExceptionsLogLevelState() = _parameters->getExceptionsLogLevelState() && (_parameters->getFileLogState() || _parameters->getConsoleLogState());
}
