#include "menumodel.h"
#include "menuparameters.h"
#include "./../../Game/gamecontroller.h"
#include "./../Options/optionsbuilder.h"
#include "./../Options/optionscontroller.h"

MenuModel::MenuModel(MenuParameters *parameters) : _parameters(parameters)
{
    _options_builder = new OptionsBuilder;
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
    GameController game;
    switch (_parameters->getCurrentOption())
    {
    case MenuParameters::START:
        game.exec();
        break;
    case MenuParameters::OPTIONS:
        (_options_builder->build())->exec();
        break;
    case MenuParameters::QUIT:
        return_value = ReturnValue::QUIT;
        break;
    }
    update();
    return return_value;
}
