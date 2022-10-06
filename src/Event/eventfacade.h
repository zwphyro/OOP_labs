#ifndef EVENTFACADE_H
#define EVENTFACADE_H

#include "addprogress.h"
#include "addenergy.h"
#include "spawnenemy.h"
#include "teleportplayer.h"

class EventFacade
{

	AddEnergy *add_energy_event;
	AddProgress *add_progress_event;
	SpawnEnemy *spawn_enemy_event;
	TeleportPlayer *teleport_player_event;

public:
	EventFacade(Field *field = nullptr, Player *player = nullptr);
	EventFacade(const EventFacade &obj);
	EventFacade &operator=(const EventFacade &obj);
	~EventFacade();

	void setPlayer(Player *player);
	void setField(Field *field);

	Event *getEvent(AddEnergy *event);
	Event *getEvent(AddProgress *event);
	Event *getEvent(SpawnEnemy *event);
	Event *getEvent(TeleportPlayer *event);
};

#endif
