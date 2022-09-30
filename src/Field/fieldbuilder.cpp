#include "fieldbuilder.h"

FieldBuilder::FieldBuilder(PlayerController *controller) : controller(controller)
{
}

Field *FieldBuilder::getField()
{
	// get field size
	Field *field = new Field;
	Player *player = new Player;
	field->addEntity(player, {0, 0});
	controller->setField(field);
	controller->setPlayer(player);
	field->setController(controller);
	player->setController(controller);

	EventFactory *factory = new EventFactory(player, field);
	field->setFactory(factory);

	field->setEvent(factory->createEvent(new SpawnEnemy), field->getRandomFreePosition());

	return field;
}
