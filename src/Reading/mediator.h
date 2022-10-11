#ifndef MEDIATOR_H
#define MEDIATOR_H

class Reader;

enum Commands
{
	UNKNOWN = -1,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	SHOOT,
	QUIT
};

class Mediator
{
public:
	Mediator();
	~Mediator();

	int getCommand();

private:
	Reader *_reader;
	int _move_up_key_code;
	int _move_down_key_code;
	int _move_left_key_code;
	int _move_right_key_code;
	int _shoot_key_code;
	int _quit_key_code;
};

#endif
