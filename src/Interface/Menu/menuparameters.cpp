#include "menuparameters.h"

MenuParameters::MenuParameters(int option) : _selected_option(option)
{
}

int MenuParameters::getCurrentOption() const
{
    return _selected_option;
}

int &MenuParameters::getCurrentOption()
{
    return _selected_option;
}
