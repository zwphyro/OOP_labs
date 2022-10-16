#include "playerevent.h"
#include "./../Entity/Player/player.h"

PlayerEvent::PlayerEvent(Player *player) : _player(player)
{
}

void PlayerEvent::setPlayer(Player *player)
{
	_player = player;
}
