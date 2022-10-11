#include "spawnenemy.h"
#include "addenergy.h"
#include "eventfacade.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Entity/enemy.h"

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
	_field->addEntity(new Enemy, _field->getRandomFreePosition());
	_field->getCell(_field->getPlayerContainer()->position)->setEvent(_field->getEventFacade().getEvent(new AddEnergy));
	_field->getCell(_field->getPlayerContainer()->position)->playerStepped();
	return true;
}
