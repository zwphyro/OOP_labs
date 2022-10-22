#include "entitycontainer.h"
#include "entity.h"

EntityContainer::EntityContainer(Entity *entity, Position position)
{
    _entity = entity;
    _position = position;
}

Entity *EntityContainer::getEntity()
{
    return _entity;
}

const Entity *EntityContainer::getEntity() const
{
    return _entity;
}

Position EntityContainer::getPosition() const
{
    return _position;
}

void EntityContainer::setEntity(Entity *entity)
{
    _entity = entity;
}

void EntityContainer::setPosition(Position position)
{
    _position = position;
}
