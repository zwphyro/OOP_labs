#include "menucontroller.h"
#include "menumodel.h"
#include <ncurses.h>

MenuController::MenuController(MenuModel *model) : _model(model)
{
}

void MenuController::setModel(MenuModel *model)
{
    _model = model;
}

void MenuController::exec()
{
    int key;
    while (true)
    {
        key = getCommand();

        if (key == 27)
            break;

        switch (key)
        {
        case KEY_DOWN:
        case KEY_RIGHT:
            _model->selectNextOption();
            break;
        case KEY_UP:
        case KEY_LEFT:
            _model->selectPreviousOption();
            break;
        case 10:
            _model->processOption();
            break;
        default:
            break;
        }
    }
}

int MenuController::getCommand()
{
    return getch();
}
