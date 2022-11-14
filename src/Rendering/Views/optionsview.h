#ifndef OPTIONSVIEW_H
#define OPTIONSVIEW_H

#include "./../view.h"
class OptionsParameters;

class OptionsView : public View
{
public:
    OptionsView(const OptionsParameters *parameters = nullptr);
    ~OptionsView();

    void setParameters(const OptionsParameters *parameters);
    void update();

private:
    const OptionsParameters *_parameters;
    void drawBorders();
    void drawOptions();
    void drawStates();
    void selectOption(int option);
};

#endif
