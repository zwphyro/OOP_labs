#include "eventfacade.h"
#include "addprogress.h"
#include "addenergy.h"
#include "spawnenemy.h"
#include "teleportplayer.h"

EventFacade::EventFacade(Field *field, Player *player)
{
	_add_energy_event = new AddEnergy(player);
	_add_progress_event = new AddProgress(player);
	_spawn_enemy_event = new SpawnEnemy(field);
	_teleport_player_event = new TeleportPlayer(field);
}

EventFacade::EventFacade(const EventFacade &obj)
{
	_add_energy_event = new AddEnergy(*obj._add_energy_event);
	_add_progress_event = new AddProgress(*obj._add_progress_event);
	_spawn_enemy_event = new SpawnEnemy(*obj._spawn_enemy_event);
	_teleport_player_event = new TeleportPlayer(*obj._teleport_player_event);
}

EventFacade &EventFacade::operator=(const EventFacade &obj)
{
	if (this != &obj)
	{
		delete _add_energy_event;
		delete _add_progress_event;
		delete _spawn_enemy_event;
		delete _teleport_player_event;

		_add_energy_event = new AddEnergy(*obj._add_energy_event);
		_add_progress_event = new AddProgress(*obj._add_progress_event);
		_spawn_enemy_event = new SpawnEnemy(*obj._spawn_enemy_event);
		_teleport_player_event = new TeleportPlayer(*obj._teleport_player_event);
	}

	return *this;
}

EventFacade::~EventFacade()
{
	delete _add_energy_event;
	delete _add_progress_event;
	delete _spawn_enemy_event;
	delete _teleport_player_event;
}

void EventFacade::setPlayer(Player *player)
{
	_add_energy_event->setPlayer(player);
	_add_progress_event->setPlayer(player);
}

void EventFacade::setField(Field *field)
{
	_spawn_enemy_event->setField(field);
	_teleport_player_event->setField(field);
}

Event *EventFacade::getEvent(AddEnergy *event)
{
	delete event;
	return _add_energy_event;
}

Event *EventFacade::getEvent(AddProgress *event)
{
	delete event;
	return _add_progress_event;
}

Event *EventFacade::getEvent(SpawnEnemy *event)
{
	delete event;
	return _spawn_enemy_event;
}

Event *EventFacade::getEvent(TeleportPlayer *event)
{
	delete event;
	return _teleport_player_event;
}
