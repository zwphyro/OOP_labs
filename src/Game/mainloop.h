#ifndef MAINLOOP_H
#define MAINLOOP_H

class Mediator;
class Painter;
class Field;
class Interactor;
class EnemyController;

class Observer;
class LogPermissions;

#include "./../Logging/observable.h"

class MainLoop : public Observable
{
public:
	MainLoop(ObserverSet *observers = nullptr);
	~MainLoop();

	int exec();

private:
	Mediator *_mediator;
	Painter *_painter;
	Field *_field;
	Interactor *_interactor;
	EnemyController *_controller;
};

#endif
