#ifndef PLAYEREVENT_H
#define PLAYEREVENT_H

#include "event.h"
#include "./../Entity/Player/player.h"

class PlayerEvent: public Event {
protected:
	Player *player;

public:
	PlayerEvent(Player *player = nullptr);
	void setPlayer(Player *player);

};

#endif
