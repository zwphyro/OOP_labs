#include <ncurses.h>
#include "consolereader.h"

int ConsoleReader::getPressedKey()
{
	return getch();
}
