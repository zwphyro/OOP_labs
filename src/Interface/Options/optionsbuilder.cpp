#include "optionsbuilder.h"
#include "optionscontroller.h"
#include "optionsmodel.h"
#include "./../../Rendering/Views/optionsview.h"
#include "optionsparameters.h"

OptionsBuilder::OptionsBuilder()
{
    _parameters = new OptionsParameters();
    _model = new OptionsModel(_parameters);
    _view = new OptionsView(_parameters);
    _controller = new OptionsController(_model);
    _model->setView(_view);
}

OptionsBuilder::~OptionsBuilder()
{
    delete _controller;
    delete _view;
    delete _model;
    delete _parameters;
}

OptionsController *OptionsBuilder::build()
{
    return _controller;
}
