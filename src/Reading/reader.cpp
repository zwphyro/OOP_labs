#include <ncurses.h>
#include "reader.h"

int Reader::getPressedKey()
{
	return getch();
}
