#include "menucontroller.h"
#include "menumodel.h"
#include "./../../Reading/consolereader.h"
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
    ConsoleReader reader;
    int key;
    int return_value = MenuModel::ReturnValue::CONTINUE;
    while (true)
    {
        key = reader.getPressedKey();

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
            return_value = _model->processOption();
            break;
        default:
            break;
        }

        if (return_value == MenuModel::ReturnValue::QUIT)
            break;
    }
}
