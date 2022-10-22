#include <iostream>
#include <cstdlib>
#include "gamecontroller.h"
#include "./Menu/menubuilder.h"
#include "./Menu/menucontroller.h"
#define USE_VALGRIND

int main(int argc, char **argv)
{
	// GameController game;
	// return game.exec();
	MenuBuilder builder;
	MenuController *controller = builder.build();
	controller->exec();
	return 0;
}
