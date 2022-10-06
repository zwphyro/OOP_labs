#include <iostream>
#include "mainloop.h"
#include <cstdlib>
#define USE_VALGRIND

int main(int argc, char **argv)
{
	MainLoop game;
	return game.exec();
}
