#include "model.h"
#include "./../Rendering/view.h"

Model::Model(View *view) : _view(view)
{
}

void Model::setView(View *view)
{
    _view = view;
}

void Model::update()
{
    _view->update();
}

View *Model::getView()
{
    return _view;
}

