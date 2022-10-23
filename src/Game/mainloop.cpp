#include "mainloop.h"
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

#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

MainLoop::MainLoop(ObserverSet *observers)
{
	makeObservable(observers);

	_mediator = new Mediator;
	Player *player = new Player;
	player->makeObservable(*this);

	_field = new Field();
	_field->makeObservable(*this);

	_interactor = new Interactor(_field, player);

	_field->addEntity(player, Position(0, 0));

	Enemy *enemy = new Enemy;
	enemy->makeObservable(*this);
	_field->addEntity(enemy, Position(3, 2));
	enemy = new Enemy;
	enemy->makeObservable(*this);
	_field->addEntity(enemy, Position(2, 3));
	enemy = new Enemy;
	enemy->makeObservable(*this);
	_field->addEntity(enemy, Position(3, 4));
	enemy = new Enemy;
	enemy->makeObservable(*this);
	_field->addEntity(enemy, Position(4, 3));

	EventFacade *event_facade = new EventFacade(_field, player);

	event_facade->getEvent(new AddEnergy)->makeObservable(*this);
	event_facade->getEvent(new AddProgress)->makeObservable(*this);
	event_facade->getEvent(new SpawnEnemy)->makeObservable(*this);
	event_facade->getEvent(new TeleportPlayer)->makeObservable(*this);

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

	notify(LogMessage(LogLevels::GAME_STATES, "game ended"));
}

int MainLoop::exec()
{
	notify(LogMessage(LogLevels::GAME_STATES, "game started"));
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
