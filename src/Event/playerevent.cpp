#include "playerevent.h"

PlayerEvent::PlayerEvent(Player *player): player(player) {

}

void PlayerEvent::setPlayer(Player *player) {
	this->player = player;
}
