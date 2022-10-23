#ifndef OPTIONSMODEL_H
#define OPTIONSMODEL_H

#include "./../../Model/model.h"
class OptionsParameters;

class OptionsModel : public Model
{
public:
    OptionsModel(OptionsParameters *parameters = nullptr);
    void setOptionsParameters(OptionsParameters *parameters);
    void selectNextOption();
    void selectPreviousOption();
    int processOption(int state);
    enum ReturnValue
    {
        CONTINUE,
        QUIT
    };

private:
    OptionsParameters *_parameters;
};

#endif
