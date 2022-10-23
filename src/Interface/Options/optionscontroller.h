#ifndef OPTIONSCONTROLLER_H
#define OPTIONSCONTROLLER_H

class OptionsModel;

class OptionsController
{
public:
    OptionsController(OptionsModel *model = nullptr);
    void setModel(OptionsModel *model);
    void exec();

private:
    OptionsModel *_model;
};

#endif
