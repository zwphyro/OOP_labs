#include "menubuilder.h"
#include "menucontroller.h"
#include "menumodel.h"
#include "menuparameters.h"
#include "./../../Rendering/Views/menuview.h"

MenuBuilder::MenuBuilder()
{
    _parameters = new MenuParameters();
    _model = new MenuModel(_parameters);
    _view = new MenuView(_parameters);
    _controller = new MenuController(_model);
    _model->setView(_view);
}

MenuBuilder::~MenuBuilder()
{
    delete _controller;
    delete _view;
    delete _model;
    delete _parameters;
}

MenuController *MenuBuilder::build()
{
    return _controller;
}
