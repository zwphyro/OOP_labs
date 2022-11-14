#include <iostream>
#include <cstdlib>
#include "./../Interface/Menu/menubuilder.h"
#include "./../Interface/Menu/menucontroller.h"
#include "./../Rendering/screeninitializer.h"
#define USE_VALGRIND

int main(int argc, char **argv)
{
	ScreenInitializer initialize;
	MenuBuilder builder;
	builder.getController()->exec();
	return 0;
}
