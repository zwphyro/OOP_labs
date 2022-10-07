#include "mainloop.h"

MainLoop::MainLoop()
{
	mediator = new Mediator;
	Player *player = new Player;

	StartDialog dialog;
	std::pair<int, int> field_sizes = dialog.getFieldSize();

	field = new Field(field_sizes.first, field_sizes.second);
	interactor = new Interactor(field, player);
	EventFacade *event_facade = new EventFacade(field, player);
	field->addEntity(player, {0, 0});
	field->setEventFacade(event_facade);
	field->getCell({1, 0})->setEvent(event_facade->getEvent(new TeleportPlayer));
	field->getCell(field->getRandomFreePosition())->setEvent(event_facade->getEvent(new SpawnEnemy));

	controller = new EnemyController(field);

	painter = new Painter;
}

MainLoop::~MainLoop()
{
	delete mediator;
	delete painter;
	delete field;
	delete interactor;
	delete controller;
}

int MainLoop::exec()
{
	int command;

	while (true)
	{
		painter->drawField(field);

		command = mediator->getCommand();

		if (command == Commands::QUIT)
			break;

		interactor->updatePlayer(command);
		controller->updateEnemys();
	}

	return 0;
}
