#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

class MenuModel;

class MenuController
{
public:
    MenuController(MenuModel *model = nullptr);
    void setModel(MenuModel *model);
    void exec();

private:
    MenuModel *_model;
    int getCommand();
};

#endif
