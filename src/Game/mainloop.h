#ifndef MAINLOOP_H
#define MAINLOOP_H

#include "./../Field/position.h"
#include "./../Reading/reader.h"
#include "./../Rendering/painter.h"
#include "./../Field/field.h"
#include "./../Field/fieldbuilder.h"
#include "./../Entity/Player/playercontroller.h"

class MainLoop {
	Reader *reader;
	Painter *painter;
	// const Field *field;
	Field *field;

	PlayerController *controller;

public:
	MainLoop();
	~MainLoop();

	int exec();

};

#endif
