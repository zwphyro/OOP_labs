#include "eventfactory.h"

EventFactory::EventFactory(Field *field, Player *player)
{
	add_energy_event = new AddEnergy(player);
	add_progress_event = new AddProgress(player);
	spawn_enemy_event = new SpawnEnemy(field);
}

EventFactory::EventFactory(const EventFactory &obj)
{
	add_energy_event = new AddEnergy(*obj.add_energy_event);
	add_progress_event = new AddProgress(*obj.add_progress_event);
	spawn_enemy_event = new SpawnEnemy(*obj.spawn_enemy_event);
}

EventFactory &EventFactory::operator=(const EventFactory &obj)
{
	if (this != &obj)
	{
		delete add_energy_event;
		delete add_progress_event;
		delete spawn_enemy_event;

		add_energy_event = new AddEnergy(*obj.add_energy_event);
		add_progress_event = new AddProgress(*obj.add_progress_event);
		spawn_enemy_event = new SpawnEnemy(*obj.spawn_enemy_event);
	}

	return *this;
}

EventFactory::~EventFactory()
{
	delete add_energy_event;
	delete add_progress_event;
	delete spawn_enemy_event;
}

void EventFactory::setPlayer(Player *player)
{
	add_energy_event->setPlayer(player);
	add_progress_event->setPlayer(player);
}

void EventFactory::setField(Field *field)
{
	spawn_enemy_event->setField(field);
}

Event *EventFactory::getEvent(AddEnergy *event)
{
	delete event;
	return add_energy_event;
}

Event *EventFactory::getEvent(AddProgress *event)
{
	delete event;
	return add_progress_event;
}

Event *EventFactory::getEvent(SpawnEnemy *event)
{
	delete event;
	return spawn_enemy_event;
}
