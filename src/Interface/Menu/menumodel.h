#ifndef MENUMODEL_H
#define MENUMODEL_H

#include "./../../Model/model.h"
class MenuParameters;
class OptionsBuilder;

class MenuModel : public Model
{
public:
    MenuModel(MenuParameters *parameters = nullptr);
    void setMenuParameters(MenuParameters *parameters);
    void selectNextOption();
    void selectPreviousOption();
    int processOption();
    enum ReturnValue
    {
        CONTINUE,
        QUIT
    };

private:
    MenuParameters *_parameters;
    OptionsBuilder *_options_builder;
};

#endif
