#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "view.h"
class MenuParameters;

class MenuView : public View
{
public:
    MenuView(const MenuParameters *parameters = nullptr);
    ~MenuView();

    void setParameters(const MenuParameters *parameters);
    void update();

private:
    const MenuParameters *_model_parameters;
    void drawBorder();
    void drawOptions();
    void selectOption(int option);
};

#endif
