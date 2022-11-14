#include "optionscontroller.h"
#include "optionsmodel.h"
#include "./../../Reading/reader.h"
#include <ncurses.h>

OptionsController::OptionsController(OptionsModel *model) : _model(model)
{
}

void OptionsController::setModel(OptionsModel *model)
{
    _model = model;
}

void OptionsController::exec()
{
    _model->update();
    Reader reader;
    int key;
    int return_value = OptionsModel::ReturnValue::CONTINUE;
    while (true)
    {
        key = reader.getPressedKey();

        if (key == 27)
            break;

        switch (key)
        {
        case KEY_UP:
            _model->selectPreviousOption();
            break;
        case KEY_DOWN:
            _model->selectNextOption();
            break;
        case KEY_RIGHT:
            return_value = _model->processOption(1);
            break;
        case KEY_LEFT:
            return_value = _model->processOption(-1);
            break;
        case 10:
            return_value = _model->processOption(0);
            break;
        }

        if (return_value == OptionsModel::ReturnValue::QUIT)
            break;
    }
}
