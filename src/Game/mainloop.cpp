#include "mainloop.h"

#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"

MainLoop::MainLoop()
{

	reader = new Reader;
	painter = new Painter;
	controller = new PlayerController;
	FieldBuilder builder(controller);
	field = builder.getField();
}

MainLoop::~MainLoop()
{
	delete reader;
	delete painter;
	delete field;
	delete controller;
}

int MainLoop::exec()
{
	enum
	{
		UNKNOWN = -1,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		SHOOT,
		QUIT
	};

	int command;

	// Enemy *enemy = new Enemy();
	// Enemy *enemy_2 = new Enemy();
	// field->addEntity(enemy, {2, 2});
	// field->addEntity(enemy_2, {4, 2});

	while (true)
	{
		painter->drawField(field);

		command = reader->getCommand();

		if (command == QUIT)
			break;

		controller->updatePlayer(command);
	}

	// delete enemy;
	// delete enemy_2;

	return 0;
}
