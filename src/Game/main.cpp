#include <iostream>
#include <cstdlib>
#include "mainloop.h"
#define USE_VALGRIND

int main(int argc, char **argv)
{
	MainLoop game;
	return game.exec();
}
