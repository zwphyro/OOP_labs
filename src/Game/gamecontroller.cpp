#include "gamecontroller.h"
#include "./../Interface/Options/optionsparameters.h"
#include "./../Field/field.h"
#include "./../Entity/Player/interactor.h"
#include "./../Entity/Enemy/enemycontroller.h"
#include "./../Rendering/painter.h"
#include "./../Reading/commands.h"
#include "./../Reading/consoleadapter.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

#include "./../FieldGeneration/fieldgenerator.h"
#include "./../FieldGeneration/playerpositionrule.h"
#include "./../FieldGeneration/enemyplacerule.h"
#include "./../FieldGeneration/mazerule.h"
#include "./../FieldGeneration/exponserule.h"
#include "./../FieldGeneration/teleportplacerule.h"
#include "./../FieldGeneration/spawnenemyplacerule.h"

GameController::GameController(const OptionsParameters *options) : _options(options)
{

    _player_controller = new Interactor;
    _enemy_controller = new EnemyController;
    _painter = new Painter;
    _command_reader = new ConsoleAdapter;
}

GameController::~GameController()
{
    delete _player_controller;
    delete _enemy_controller;
    delete _painter;
    delete _command_reader;
}

void GameController::setOptions(const OptionsParameters *options)
{
    _options = options;
}

int GameController::exec()
{
    if (_options == nullptr)
        return 0;

    FieldGeneratorStrategy *generator = _options->getFieldGenerator();
    Field *field = generator->getField(_options);

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

    while (!field->getGameStatus() && command != Commands::QUIT)
    {
        command = _command_reader->getCommand();

        _player_controller->updatePlayer(command);
        _enemy_controller->updateEnemys();
        _painter->drawField(field);
    }

    while (command != Commands::QUIT)
        command = _command_reader->getCommand();

    notify(LogMessage(LogLevels::GAME_STATES, "Object: GameController; Event: game ended;"));
    return 0;
}
