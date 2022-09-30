#include "spawnenemy.h"
#include "./../Field/field.h"

SpawnEnemy::SpawnEnemy(Field *field): FieldEvent(field) {
	
}

SpawnEnemy::SpawnEnemy(const SpawnEnemy& obj) {
	field = obj.field;
}

SpawnEnemy& SpawnEnemy::operator=(const SpawnEnemy& obj) {
	if (this != &obj)
		field = obj.field;
	return *this;
}

bool SpawnEnemy::action() {
	field->addEntity(new Enemy, field->getRandomFreePosition());
	field->setEvent(field->getFactory().createEvent(new AddEnergy), field->getPlayerContainer().position);
	return true;
}
