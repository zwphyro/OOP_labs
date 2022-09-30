#ifndef MEDIATOR_H
#define MEDIATOR_H

class Field;
class Player;

#include "./../entity.h"
#include "./../../Field/position.h"

class PlayerController {
	Field *field;
	Player *player;

public:
	PlayerController(Field *field = nullptr, Player *player = nullptr);
	~PlayerController();

	void setPlayer(Player *player);
	void setField(Field *field);

	void updatePlayer(int command);

	void movePlayer(int direction);
	void shoot();

};

#endif
