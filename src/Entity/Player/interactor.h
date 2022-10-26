#ifndef INTERACTOR_H
#define INTERACTOR_H

class Field;
class Player;
class Position;

class Interactor
{
public:
	Interactor(Field *field = nullptr);
	~Interactor();

	void setField(Field *field);

	void updatePlayer(int command);

private:
	Field *_field;
	Player *_player;

	void movePlayer(int direction);
	void shoot();
};

#endif
