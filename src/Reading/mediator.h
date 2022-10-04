#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "reader.h"

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
	Reader *reader;
	int move_up_key_code;
	int move_down_key_code;
	int move_left_key_code;
	int move_right_key_code;
	int shoot_key_code;
	int quit_key_code;

public:
	Mediator();
	~Mediator();

	int getCommand();
};

#endif
