#ifndef OPTIONSBUILDER_H
#define OPTIONSBUILDER_H

class OptionsController;
class OptionsModel;
class OptionsView;
class OptionsParameters;

class OptionsBuilder
{
public:
    OptionsBuilder();
    ~OptionsBuilder();
    OptionsController *getController();
    OptionsParameters *getParameters();

private:
    OptionsController *_controller;
    OptionsModel *_model;
    OptionsView *_view;
    OptionsParameters *_parameters;
};

#endif
