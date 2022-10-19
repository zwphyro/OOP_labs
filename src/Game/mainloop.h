#ifndef MAINLOOP_H
#define MAINLOOP_H

class Mediator;
class Painter;
class Field;
class Interactor;
class EnemyController;

class FileLogger;
class LogPermissions;

class MainLoop
{
public:
	MainLoop();
	~MainLoop();

	int exec();

private:
	Mediator *_mediator;
	Painter *_painter;
	Field *_field;
	Interactor *_interactor;
	EnemyController *_controller;

	FileLogger *_logger;
	LogPermissions *_permissions;
};

#endif
