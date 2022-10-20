#include <iostream>
#include <cstdlib>
#include "gamecontroller.h"
#define USE_VALGRIND

int main(int argc, char **argv)
{
	GameController game;
	return game.exec();
}
