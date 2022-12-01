#ifndef OPTIONSMODEL_H
#define OPTIONSMODEL_H

#include "./../../Model/model.h"
#include <map>
#include <functional>
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
    static std::map<const int, std::function<void(OptionsModel &, int)>> _performed_functions;

    void changeGenerator(int state);
    void changeWidth(int state);
    void changeHeight(int state);
    void changeConsoleLogState(int);
    void changeFileLogState(int);
    void changeEntitiesLogLevelState(int);
    void changeGameLevelsLogLevelState(int);
    void changeExceptionsLogLevelState(int);

    void updateLogLevels();
};

#endif
