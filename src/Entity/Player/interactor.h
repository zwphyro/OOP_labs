#ifndef INTERACTOR_H
#define INTERACTOR_H

class Field;
class Player;

#include "./../entity.h"
#include "./../../Field/position.h"

class Interactor
{
	Field *field;
	Player *player;

public:
	Interactor(Field *field = nullptr, Player *player = nullptr);
	~Interactor();

	void setPlayer(Player *player);
	void setField(Field *field);

	void updatePlayer(int command);
	Position calculateSidePosition(Position position, int direction);

	void movePlayer(int direction);
	void shoot();
};

#endif
