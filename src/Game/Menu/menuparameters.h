#ifndef MENUPARAMETERS_H
#define MENUPARAMETERS_H

#define PARAMETERS_COUNT 4
enum
{
    START,
    LOAD,
    OPTIONS,
    QUIT
};

class MenuParameters
{
public:
    MenuParameters(int option = START);
    int getCurrentOption() const;
    int &getCurrentOption();

private:
    int _selected_option;
};

#endif
