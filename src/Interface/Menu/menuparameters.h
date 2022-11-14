#ifndef MENUPARAMETERS_H
#define MENUPARAMETERS_H

#define MENU_PARAMETERS_COUNT 4

class MenuParameters
{
public:
    MenuParameters(int option = START);
    int getCurrentOption() const;
    int &getCurrentOption();
    enum
    {
        START,
        LOAD,
        OPTIONS,
        QUIT
    };

private:
    int _selected_option;
};

#endif
