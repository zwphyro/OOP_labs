#ifndef EVENTFACADE_H
#define EVENTFACADE_H

class Event;
class Field;
class Player;
class AddProgress;
class AddEnergy;
class SpawnEnemy;
class TeleportPlayer;

class EventFacade
{
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

private:
	AddEnergy *_add_energy_event;
	AddProgress *_add_progress_event;
	SpawnEnemy *_spawn_enemy_event;
	TeleportPlayer *_teleport_player_event;
};

#endif
