#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class OptionsParameters;
class Interactor;
class EnemyController;
class Painter;
class Mediator;
class Field;

#include "./../Logging/observable.h"

class GameController : public Observable
{
public:
    GameController(const OptionsParameters *options = nullptr);
    ~GameController();
    void setOptions(const OptionsParameters *options);
    int exec();
    int exec(Field *field);

private:
    const OptionsParameters *_options;
    Interactor *_player_controller;
    EnemyController *_enemy_controller;
    Painter *_painter;
    Mediator *_mediator;
};

#endif
