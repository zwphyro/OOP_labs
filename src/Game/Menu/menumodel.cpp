#include "menumodel.h"
#include "menuparameters.h"
#include "./../gamecontroller.h"

MenuModel::MenuModel(MenuParameters *parameters) : _parameters(parameters)
{
}

void MenuModel::selectNextOption()
{
    _parameters->getCurrentOption() = (_parameters->getCurrentOption() + 1) % PARAMETERS_COUNT;
    update();
}

void MenuModel::selectPreviousOption()
{
    _parameters->getCurrentOption() = (_parameters->getCurrentOption() + PARAMETERS_COUNT - 1) % PARAMETERS_COUNT;
    update();
}

void MenuModel::processOption()
{
    switch (_parameters->getCurrentOption())
    {
    case START:
        GameController game;
        game.exec();
        break;
    }
}
