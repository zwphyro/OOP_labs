#include "mediator.h"

Mediator::Mediator()
{
	reader = new Reader;
	move_up_key_code = 259;
	move_down_key_code = 258;
	move_left_key_code = 261;
	move_right_key_code = 260;
	shoot_key_code = ' ';
	quit_key_code = 'q';
}

Mediator::~Mediator()
{
	delete reader;
}

int Mediator::getCommand()
{
	int key = reader->getPressedKey();

	if (key == move_up_key_code)
		return Commands::MOVE_UP;
	else if (key == move_down_key_code)
		return Commands::MOVE_DOWN;
	else if (key == move_left_key_code)
		return Commands::MOVE_LEFT;
	else if (key == move_right_key_code)
		return Commands::MOVE_RIGHT;
	else if (key == quit_key_code)
		return Commands::QUIT;
	else if (key == shoot_key_code)
		return Commands::SHOOT;
	return Commands::UNKNOWN;
}
