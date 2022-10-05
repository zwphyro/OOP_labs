#include "mainloop.h"

MainLoop::MainLoop()
{
	mediator = new Mediator;
	Player *player = new Player;

	// get field size

	StartDialog dialog;
	std::pair<int, int> field_sizes = dialog.getFieldSize();

	field = new Field(field_sizes.first, field_sizes.second);
	interactor = new Interactor(field, player);
	EventFactory *factory = new EventFactory(field, player);
	field->addEntity(player, {0, 0});
	field->setFactory(factory);
	field->getCell({1, 0})->setEvent(factory->getEvent(new TeleportPlayer));
	field->getCell(field->getRandomFreePosition())->setEvent(factory->getEvent(new SpawnEnemy));

	painter = new Painter;
}

MainLoop::~MainLoop()
{
	delete mediator;
	delete painter;
	delete field;
	delete interactor;
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
	}

	return 0;
}
