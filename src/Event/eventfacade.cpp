#include "eventfacade.h"

EventFacade::EventFacade(Field *field, Player *player)
{
	add_energy_event = new AddEnergy(player);
	add_progress_event = new AddProgress(player);
	spawn_enemy_event = new SpawnEnemy(field);
	teleport_player_event = new TeleportPlayer(field);
}

EventFacade::EventFacade(const EventFacade &obj)
{
	add_energy_event = new AddEnergy(*obj.add_energy_event);
	add_progress_event = new AddProgress(*obj.add_progress_event);
	spawn_enemy_event = new SpawnEnemy(*obj.spawn_enemy_event);
	teleport_player_event = new TeleportPlayer(*obj.teleport_player_event);
}

EventFacade &EventFacade::operator=(const EventFacade &obj)
{
	if (this != &obj)
	{
		delete add_energy_event;
		delete add_progress_event;
		delete spawn_enemy_event;
		delete teleport_player_event;

		add_energy_event = new AddEnergy(*obj.add_energy_event);
		add_progress_event = new AddProgress(*obj.add_progress_event);
		spawn_enemy_event = new SpawnEnemy(*obj.spawn_enemy_event);
		teleport_player_event = new TeleportPlayer(*obj.teleport_player_event);
	}

	return *this;
}

EventFacade::~EventFacade()
{
	delete add_energy_event;
	delete add_progress_event;
	delete spawn_enemy_event;
	delete teleport_player_event;
}

void EventFacade::setPlayer(Player *player)
{
	add_energy_event->setPlayer(player);
	add_progress_event->setPlayer(player);
}

void EventFacade::setField(Field *field)
{
	spawn_enemy_event->setField(field);
	teleport_player_event->setField(field);
}

Event *EventFacade::getEvent(AddEnergy *event)
{
	delete event;
	return add_energy_event;
}

Event *EventFacade::getEvent(AddProgress *event)
{
	delete event;
	return add_progress_event;
}

Event *EventFacade::getEvent(SpawnEnemy *event)
{
	delete event;
	return spawn_enemy_event;
}

Event *EventFacade::getEvent(TeleportPlayer *event)
{
	delete event;
	return teleport_player_event;
}
