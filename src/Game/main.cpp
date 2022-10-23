#include <iostream>
#include <cstdlib>
#include "./../Interface/Menu/menubuilder.h"
#include "./../Interface/Menu/menucontroller.h"
#include "./../Rendering/screeninitializer.h"
#define USE_VALGRIND

int main(int argc, char **argv)
{
	// GameController game;
	// return game.exec();
	ScreenInitializer initialize;
	MenuBuilder builder;
	MenuController *controller = builder.build();
	controller->exec();
	return 0;
}
