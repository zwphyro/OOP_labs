#ifndef MENUMODEL_H
#define MENUMODEL_H

#include "model.h"
class MenuParameters;

class MenuModel : public Model
{
public:
    MenuModel(MenuParameters *parameters = nullptr);
    void setMenuparameters(MenuParameters *parameters);
    void selectNextOption();
    void selectPreviousOption();
    void processOption();

private:
    MenuParameters *_parameters;
};

#endif
