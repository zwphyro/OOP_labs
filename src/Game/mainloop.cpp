#include "mainloop.h"
#include "./../Reading/startdialog.h"
#include "./../Reading/mediator.h"
#include "./../Reading/commands.h"
#include "./../Entity/enemy.h"
#include "./../Entity/Enemy/enemycontroller.h"
#include "./../Entity/Player/interactor.h"
#include "./../Entity/Player/player.h"
#include "./../Event/addenergy.h"
#include "./../Event/addprogress.h"
#include "./../Event/teleportplayer.h"
#include "./../Event/spawnenemy.h"
#include "./../Event/eventfacade.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Field/position.h"
#include "./../Rendering/painter.h"

#include "./../Logging/filelogger.h"
#include "./../Logging/logpermissions.h"
#include "./../Logging/loglevel.h"

MainLoop::MainLoop()
{
	LogPermissions *permissions = new LogPermissions;
	FileLogger *logger = new FileLogger();
	logger->setLogPermissions(permissions);
	_mediator = new Mediator;
	Player *player = new Player;
	player->addObserver(logger);
	StartDialog dialog;
	std::pair<int, int> field_sizes = dialog.getFieldSize();

	_field = new Field(field_sizes.first, field_sizes.second);
	_field->addObserver(logger);
	_interactor = new Interactor(_field, player);
	EventFacade *event_facade = new EventFacade(_field, player);
	event_facade->getEvent(new AddEnergy)->addObserver(logger);
	event_facade->getEvent(new AddProgress)->addObserver(logger);
	event_facade->getEvent(new SpawnEnemy)->addObserver(logger);
	event_facade->getEvent(new TeleportPlayer)->addObserver(logger);

	_field->addEntity(player, Position(0, 0));

	_field->addEntity(new Enemy, Position(3, 2));
	_field->addEntity(new Enemy, Position(2, 3));
	_field->addEntity(new Enemy, Position(3, 4));
	_field->addEntity(new Enemy, Position(4, 3));

	_field->setEventFacade(event_facade);
	if (_field->getCell(Position(1, 0)))
		_field->getCell(Position(1, 0))->setEvent(event_facade->getEvent(new TeleportPlayer));
	if (_field->getCell(Position(2, 2)))
		_field->getCell(Position(2, 2))->setEvent(event_facade->getEvent(new TeleportPlayer));
	Position random_position = _field->getRandomFreePosition();
	if (Position(-1, -1) != random_position)
		_field->getCell(random_position)->setEvent(event_facade->getEvent(new SpawnEnemy));

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
