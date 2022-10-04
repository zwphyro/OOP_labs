#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include "./../Entity/Player/interactor.h"
#include "field.h"
#include "./../Entity/Player/player.h"
#include "./../Event/eventfactory.h"

class FieldBuilder
{
	Interactor *interactor;

public:
	FieldBuilder(Interactor *interactor);
	Field *getField();
};

#endif
