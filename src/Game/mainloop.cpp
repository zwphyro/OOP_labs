#include "mainloop.h"
#include "./../Reading/startdialog.h"
#include "./../Reading/mediator.h"
#include "./../Reading/commands.h"
#include "./../Entity/enemy.h"
#include "./../Entity/Enemy/enemycontroller.h"
#include "./../Entity/Player/interactor.h"
#include "./../Entity/Player/player.h"
#include "./../Event/teleportplayer.h"
#include "./../Event/spawnenemy.h"
#include "./../Event/eventfacade.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Field/position.h"
#include "./../Rendering/painter.h"

#include "./../Logging/filelogger.h"

MainLoop::MainLoop()
{
	_mediator = new Mediator;
	Player *player = new Player;

	StartDialog dialog;
	std::pair<int, int> field_sizes = dialog.getFieldSize();

	_field = new Field(field_sizes.first, field_sizes.second);
	_interactor = new Interactor(_field, player);
	EventFacade *event_facade = new EventFacade(_field, player);
	_field->addEntity(player, Position(0, 0));
	// _field->addEntity(new Enemy, Position(3, 2));
	// _field->addEntity(new Enemy, Position(2, 3));
	// _field->addEntity(new Enemy, Position(3, 4));
	// _field->addEntity(new Enemy, Position(4, 3));

	_field->setEventFacade(event_facade);
	if (_field->getCell(Position(1, 0)))
		_field->getCell(Position(1, 0))->setEvent(event_facade->getEvent(new TeleportPlayer));
	if (_field->getCell(Position(2, 2)))
		_field->getCell(Position(2, 2))->setEvent(event_facade->getEvent(new TeleportPlayer));
	_field->getCell(_field->getRandomFreePosition())->setEvent(event_facade->getEvent(new SpawnEnemy));

	_controller = new EnemyController(_field);

	_painter = new Painter;
}

MainLoop::~MainLoop()
{
	delete _mediator;
	delete _painter;
	delete _field;
	delete _interactor;
	delete _controller;
}

int MainLoop::exec()
{
	int command;

	while (true)
	{
		_painter->drawField(_field);

		command = _mediator->getCommand();

		if (command == Commands::QUIT)
			break;

		_interactor->updatePlayer(command);
		_controller->updateEnemys();
	}

	return 0;
}
