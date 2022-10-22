#ifndef ENTITYCONTAINER_H
#define ENTITYCONTAINER_H

class Entity;
#include "./../Field/position.h"

class EntityContainer
{
public:
	EntityContainer(Entity *entity = nullptr, Position position = Position());
	Entity *getEntity();
	const Entity *getEntity() const;
	Position getPosition() const;

	void setEntity(Entity *entity);
	void setPosition(Position position);

private:
	Entity *_entity;
	Position _position;
};

#endif
