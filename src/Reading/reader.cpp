#include <ncurses.h>
#include "reader.h"

int Reader::getPressedKey()
{
	return getch();
}

int Reader::getCommand()
{
	int key = getPressedKey();

	enum
	{
		UNKNOWN = -1,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		SHOOT,
		QUIT
	};

	switch (key)
	{
	case 259:
		return MOVE_UP;
	case 258:
		return MOVE_DOWN;
	case 261:
		return MOVE_LEFT;
	case 260:
		return MOVE_RIGHT;
	case 'q':
		return QUIT;
	case ' ':
		return SHOOT;
	default:
		return UNKNOWN;
	}
}
