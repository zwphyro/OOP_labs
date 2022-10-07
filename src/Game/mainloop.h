#ifndef MAINLOOP_H
#define MAINLOOP_H

#include "./../Reading/startdialog.h"
#include "./../Field/position.h"
#include "./../Reading/mediator.h"
#include "./../Rendering/painter.h"
#include "./../Field/field.h"
#include "./../Entity/Player/interactor.h"
#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"
#include "./../Entity/Enemy/enemycontroller.h"

class MainLoop
{
	Mediator *mediator;
	Painter *painter;
	Field *field;

	Interactor *interactor;
	EnemyController *controller;

public:
	MainLoop();
	~MainLoop();

	int exec();
};

#endif
