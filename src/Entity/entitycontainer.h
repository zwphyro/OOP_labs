#ifndef ENTITYCONTAINER_H
#define ENTITYCONTAINER_H

#include "entity.h"
#include "./../Field/position.h"

struct EntityContainer
{
	Entity *entity;
	Position position;
};

#endif
