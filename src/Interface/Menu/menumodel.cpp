#include "menumodel.h"
#include "menuparameters.h"
#include "./../Options/optionsbuilder.h"
#include "./../Options/optionscontroller.h"
#include "./../../Game/gamecontroller.h"
#include "./../../Logging/logsystem.h"

MenuModel::MenuModel(MenuParameters *parameters) : _parameters(parameters)
{
    _options_builder = new OptionsBuilder;
    _game_controller = new GameController(_options_builder->getParameters());
    _log_sustem = new LogSystem(_options_builder->getParameters());
    _game_controller->makeObservable(_log_sustem->getObservers());
}

MenuModel::~MenuModel()
{
    delete _options_builder;
    delete _game_controller;
    delete _log_sustem;
}

void MenuModel::setMenuParameters(MenuParameters *parameters)
{
    _parameters = parameters;
}

void MenuModel::selectNextOption()
{
    _parameters->getCurrentOption() = (_parameters->getCurrentOption() + 1) % MENU_PARAMETERS_COUNT;
    update();
}

void MenuModel::selectPreviousOption()
{
    _parameters->getCurrentOption() = (_parameters->getCurrentOption() + MENU_PARAMETERS_COUNT - 1) % MENU_PARAMETERS_COUNT;
    update();
}

int MenuModel::processOption()
{
    int return_value = ReturnValue::CONTINUE;

    switch (_parameters->getCurrentOption())
    {
    case MenuParameters::START:
        _log_sustem->updateParameters();
        _game_controller->exec();
        break;
    case MenuParameters::OPTIONS:
        _options_builder->getController()->exec();
        break;
    case MenuParameters::QUIT:
        return_value = ReturnValue::QUIT;
        break;
    }
    update();
    return return_value;
}
