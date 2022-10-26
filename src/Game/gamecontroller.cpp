#include "gamecontroller.h"
#include "./../Interface/Options/optionsparameters.h"
#include "./../Field/field.h"
#include "./../Entity/Player/interactor.h"
#include "./../Entity/Enemy/enemycontroller.h"
#include "./../Rendering/painter.h"
#include "./../Reading/mediator.h"
#include "./../Reading/commands.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

#include "./../Entity/enemy.h"
#include "./../Field/cell.h"
#include "./../Event/eventfacade.h"
#include "./../Event/addenergy.h"
#include "./../Event/addprogress.h"
#include "./../Event/teleportplayer.h"
#include "./../Event/spawnenemy.h"

GameController::GameController(const OptionsParameters *options) : _options(options)
{

    _player_controller = new Interactor;
    _enemy_controller = new EnemyController;
    _painter = new Painter;
    _mediator = new Mediator;
}

GameController::~GameController()
{
    delete _player_controller;
    delete _enemy_controller;
    delete _painter;
    delete _mediator;
}

void GameController::setOptions(const OptionsParameters *options)
{
    _options = options;
}

int GameController::exec()
{
    if (_options == nullptr)
        return 0;
    Field *field = new Field(_options);
    field->makeObservable(*this);
    field->getPlayerContainer()->getEntity()->makeObservable(*this);
    field->getEventFacade()->getEvent(new AddEnergy)->makeObservable(*this);
    field->getEventFacade()->getEvent(new AddProgress)->makeObservable(*this);
    field->getEventFacade()->getEvent(new SpawnEnemy)->makeObservable(*this);
    field->getEventFacade()->getEvent(new TeleportPlayer)->makeObservable(*this);

    field->addEntity(new Enemy, Position(3, 2));
    field->addEntity(new Enemy, Position(2, 3));
    field->addEntity(new Enemy, Position(3, 4));
    field->addEntity(new Enemy, Position(4, 3));
    field->getCell(Position(1, 0))->setEvent(field->getEventFacade()->getEvent(new TeleportPlayer));
    field->getCell(Position(2, 2))->setEvent(field->getEventFacade()->getEvent(new TeleportPlayer));
    Position random_position = field->getRandomFreePosition();
    if (Position(-1, -1) != random_position)
        field->getCell(random_position)->setEvent(field->getEventFacade()->getEvent(new SpawnEnemy));

    exec(field);
    delete field;
    return 0;
}

int GameController::exec(Field *field)
{
    notify(LogMessage(LogLevels::GAME_STATES, "Object: GameController; Event: game stared;"));
    _player_controller->setField(field);
    _enemy_controller->setField(field);

    int command;

    while (true)
    {
        _painter->drawField(field);

        command = _mediator->getCommand();

        if (command == Commands::QUIT)
            break;

        _player_controller->updatePlayer(command);
        _enemy_controller->updateEnemys();
    }
    notify(LogMessage(LogLevels::GAME_STATES, "Object: GameController; Event: game ended;"));
    return 0;
}
