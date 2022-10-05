#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "addprogress.h"
#include "addenergy.h"
#include "spawnenemy.h"
#include "teleportplayer.h"

class EventFactory
{

	AddEnergy *add_energy_event;
	AddProgress *add_progress_event;
	SpawnEnemy *spawn_enemy_event;
	TeleportPlayer *teleport_player_event;

public:
	EventFactory(Field *field = nullptr, Player *player = nullptr);
	EventFactory(const EventFactory &obj);
	EventFactory &operator=(const EventFactory &obj);
	~EventFactory();

	void setPlayer(Player *player);
	void setField(Field *field);

	Event *getEvent(AddEnergy *event);
	Event *getEvent(AddProgress *event);
	Event *getEvent(SpawnEnemy *event);
	Event *getEvent(TeleportPlayer *event);
};

#endif
