#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include "./../Entity/Player/playercontroller.h"
#include "field.h"
#include "./../Entity/Player/player.h"
#include "./../Event/eventfactory.h"

class FieldBuilder
{
	PlayerController *controller;

public:
	FieldBuilder(PlayerController *controller);
	Field *getField();
};

#endif
