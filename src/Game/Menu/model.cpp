#include "model.h"
#include "view.h"

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
