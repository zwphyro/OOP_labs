#ifndef TELEPORTPLACERULE_H
#define TELEPORTPLACERULE_H

#include "./../Field/field.h"
#include "./../Field/cell.h"
#include "./../Field/position.h"
#include "./../Event/eventfacade.h"
#include "./../Event/teleportplayer.h"

template <int teleports_count>
class TeleportPlaceRule
{
public:
    void apply(Field *field);
};

template <int teleports_count>
void TeleportPlaceRule<teleports_count>::apply(Field *field)
{
    for (int i = 0; i < teleports_count; i++)
    {
        Position random_position = field->getRandomFreePosition();
        if (random_position == Position(-1, -1))
            return;
        field->getCell(random_position)->setEvent(field->getEventFacade()->getEvent(new TeleportPlayer));
    }
}

#endif
