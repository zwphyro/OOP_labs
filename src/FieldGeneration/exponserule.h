#ifndef EXPONSERULE_H
#define EXPONSERULE_H

#include "./../Field/field.h"
#include "./../Field/position.h"
#include "./../Entity/Player/player.h"

template <int walls_percent>
class ExponseRule
{
public:
    void apply(Field *field);
};

template <int walls_percent>
void ExponseRule<walls_percent>::apply(Field *field)
{
    for (int i = 0; i < walls_percent * field->getWidth() * field->getHeight() / 100; i++)
    {
        Position random_position = field->getRandomFreePosition();
        if (random_position == Position(-1, -1))
            return;
        field->addWall(random_position);
    }
}

#endif
