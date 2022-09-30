#include "playercontroller.h"
#include "player.h"
#include "./../../Field/field.h"

PlayerController::PlayerController(Field *field, Player *player):field(field), player(player){

}

PlayerController::~PlayerController() {
	if (player) delete player;
}

void PlayerController::setPlayer(Player *player) {
	this->player = player;
}

void PlayerController::setField(Field *field) {
	this->field = field;
}

void PlayerController::updatePlayer(int command) {
	enum {UP, DOWN, RIGHT, LEFT, SHOOT};

	player->changeEnergy();
	player->changeProgress();
	player->changeSpeed();

	switch (command) {
		case UP:
		case DOWN:
		case LEFT:
		case RIGHT:
			movePlayer(command);
			break;
		case SHOOT:
			shoot();
			break;
		default:
			break;
	}

}

void PlayerController::movePlayer(int direction) {
	if (player == nullptr || field == nullptr) return;
	
	if (!player->moveStart(direction)) return;

	if (field->movePlayer(direction))
		player->moveCommited();
}

void PlayerController::shoot() {
	if (!player->shootStart()) return; 
	player->changeEnergy(-100);
	field->processDamage(player->getDirection());
}
