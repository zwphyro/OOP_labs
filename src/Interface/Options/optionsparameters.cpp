#include "optionsparameters.h"
#include "./../../FieldGeneration/fieldgenerator.h"
#include "./../../FieldGeneration/playerpositionrule.h"
#include "./../../FieldGeneration/enemyplacerule.h"
#include "./../../FieldGeneration/mazerule.h"
#include "./../../FieldGeneration/exponserule.h"
#include "./../../FieldGeneration/teleportplacerule.h"
#include "./../../FieldGeneration/spawnenemyplacerule.h"

OptionsParameters::OptionsParameters()
{
    _selected_option = GENERATOR;
    _field_generator = Generator::MAZE;
    _field_width = 20;
    _field_height = 20;
    _console_log_state = false;
    _file_log_state = false;
    _game_entities_log_level_state = false;
    _game_states_log_level_state = false;
    _exceptions_log_level_state = false;

    _field_renerator_map[Generator::MAZE] = new FieldGenerator<PlayerPositionRule<3, 3>, MazeRule<60>, EnemyPlaceRule<6>, TeleportPlaceRule<3>>;
    _field_renerator_map[Generator::EXPONSE] = new FieldGenerator<PlayerPositionRule<>, SpawnEnemyPlaceRule<6>, TeleportPlaceRule<9>, ExponseRule<20>>;
}

OptionsParameters::~OptionsParameters()
{
    delete _field_renerator_map[Generator::MAZE];
    delete _field_renerator_map[Generator::EXPONSE];
}

int OptionsParameters::getCurrentOption() const
{
    return _selected_option;
}

FieldGeneratorStrategy *OptionsParameters::getFieldGenerator() const
{
    return _field_renerator_map.at(_field_generator);
}

Generator OptionsParameters::getFieldGenerator(int) const
{
    return _field_generator;
}

Generator &OptionsParameters::getFieldGenerator()
{
    return _field_generator;
}

int &OptionsParameters::getCurrentOption()
{
    return _selected_option;
}

int OptionsParameters::getFieldWidth() const
{
    return _field_width;
}

int &OptionsParameters::getFieldWidth()
{
    return _field_width;
}

int OptionsParameters::getFieldHeight() const
{
    return _field_height;
}

int &OptionsParameters::getFieldHeight()
{
    return _field_height;
}

bool OptionsParameters::getConsoleLogState() const
{
    return _console_log_state;
}

bool &OptionsParameters::getConsoleLogState()
{
    return _console_log_state;
}

bool OptionsParameters::getFileLogState() const
{
    return _file_log_state;
}

bool &OptionsParameters::getFileLogState()
{
    return _file_log_state;
}

bool OptionsParameters::getEntitiesLogLevelState() const
{
    return _game_entities_log_level_state;
}

bool &OptionsParameters::getEntitiesLogLevelState()
{
    return _game_entities_log_level_state;
}

bool OptionsParameters::getGameStatesLogLevelState() const
{
    return _game_states_log_level_state;
}

bool &OptionsParameters::getGameStatesLogLevelState()
{
    return _game_states_log_level_state;
}

bool OptionsParameters::getExceptionsLogLevelState() const
{
    return _exceptions_log_level_state;
}

bool &OptionsParameters::getExceptionsLogLevelState()
{
    return _exceptions_log_level_state;
}
