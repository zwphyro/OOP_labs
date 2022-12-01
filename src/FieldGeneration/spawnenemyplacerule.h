#ifndef SPAWNENEMYRULE_H
#define SPAWNENEMYRULE_H

#include "./../Field/field.h"
#include "./../Field/cell.h"
#include "./../Field/position.h"
#include "./../Event/eventfacade.h"
#include "./../Event/spawnenemy.h"

template <int spawns_count>
class SpawnEnemyPlaceRule
{
public:
    void apply(Field *field);
};

template <int spawns_count>
void SpawnEnemyPlaceRule<spawns_count>::apply(Field *field)
{
    for (int i = 0; i < spawns_count; i++)
    {
        Position random_position = field->getRandomFreePosition();
        if (random_position == Position(-1, -1))
            return;
        field->getCell(random_position)->setEvent(field->getEventFacade()->getEvent(new SpawnEnemy));
    }
}

#endif
