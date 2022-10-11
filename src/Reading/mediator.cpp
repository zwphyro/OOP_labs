#include "mediator.h"
#include "reader.h"

Mediator::Mediator()
{
	_reader = new Reader;
	_move_up_key_code = 259;
	_move_down_key_code = 258;
	_move_left_key_code = 261;
	_move_right_key_code = 260;
	_shoot_key_code = ' ';
	_quit_key_code = 'q';
}

Mediator::~Mediator()
{
	delete _reader;
}

int Mediator::getCommand()
{
	int key = _reader->getPressedKey();

	if (key == _move_up_key_code)
		return Commands::MOVE_UP;
	else if (key == _move_down_key_code)
		return Commands::MOVE_DOWN;
	else if (key == _move_left_key_code)
		return Commands::MOVE_LEFT;
	else if (key == _move_right_key_code)
		return Commands::MOVE_RIGHT;
	else if (key == _quit_key_code)
		return Commands::QUIT;
	else if (key == _shoot_key_code)
		return Commands::SHOOT;
	return Commands::UNKNOWN;
}
