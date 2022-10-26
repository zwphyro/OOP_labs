#ifndef MENUBUILDER_H
#define MENUBUILDER_H

class MenuController;
class MenuModel;
class MenuView;
class MenuParameters;

class MenuBuilder
{
public:
    MenuBuilder();
    ~MenuBuilder();
    MenuController *getController();

private:
    MenuController *_controller;
    MenuModel *_model;
    MenuView *_view;
    MenuParameters *_parameters;
};

#endif
