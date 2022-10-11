#ifndef PLAYEREVENT_H
#define PLAYEREVENT_H

#include "event.h"
class Player;

class PlayerEvent : public Event
{
public:
	PlayerEvent(Player *player = nullptr);
	void setPlayer(Player *player);

protected:
	Player *_player;
};

#endif
