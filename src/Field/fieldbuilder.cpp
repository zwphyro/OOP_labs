#include "fieldbuilder.h"

FieldBuilder::FieldBuilder(Interactor *interactor) : interactor(interactor)
{
}

Field *FieldBuilder::getField()
{
	// get field size
	Field *field = new Field(8, 6);
	Player *player = new Player;
	field->addEntity(player, {0, 0});
	interactor->setField(field);
	interactor->setPlayer(player);
	player->setInteractor(interactor);

	EventFactory *factory = new EventFactory(player, field);
	field->setFactory(factory);

	field->getCell(field->getRandomFreePosition())->setEvent(factory->createEvent(new SpawnEnemy));

	return field;
}
