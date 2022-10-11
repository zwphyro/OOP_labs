#ifndef INTERACTOR_H
#define INTERACTOR_H

class Field;
class Player;
class Position;

enum Direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Interactor
{
public:
	Interactor(Field *field = nullptr, Player *player = nullptr);
	~Interactor();

	void setPlayer(Player *player);
	void setField(Field *field);

	void updatePlayer(int command);

private:
	Field *_field;
	Player *_player;

	Position calculateSidePosition(Position position, int direction);
	void movePlayer(int direction);
	void shoot();
};

#endif
