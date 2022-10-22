#include "spawnenemy.h"
#include "addenergy.h"
#include "eventfacade.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Entity/enemy.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

SpawnEnemy::SpawnEnemy(Field *field) : FieldEvent(field)
{
}

SpawnEnemy::SpawnEnemy(const SpawnEnemy &obj)
{
	_field = obj._field;
}

SpawnEnemy &SpawnEnemy::operator=(const SpawnEnemy &obj)
{
	if (this != &obj)
		_field = obj._field;
	return *this;
}

bool SpawnEnemy::action()
{
	Position random_position = _field->getRandomFreePosition();
	if (Position(-1, -1) == random_position)
		return false;

	Enemy *new_enemy = new Enemy;
	new_enemy->makeObservable(*this);

	_field->addEntity(new_enemy, random_position);
	_field->getCell(_field->getPlayerContainer()->getPosition())->setEvent(_field->getEventFacade().getEvent(new AddEnergy));
	_field->getCell(_field->getPlayerContainer()->getPosition())->playerStepped();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "event SpawnEnemy triggered"));
	return true;
}
