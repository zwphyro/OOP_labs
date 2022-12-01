#ifndef ENEMYPLACERULE_H
#define ENEMYPLACERULE_H

#include "./../Field/field.h"
#include "./../Field/position.h"
#include "./../Entity/enemy.h"

template <size_t enemy_count = 1>
class EnemyPlaceRule
{
public:
    void apply(Field *field);
};

template <size_t enemy_count>
void EnemyPlaceRule<enemy_count>::apply(Field *field)
{
    for (int i = 0; i < enemy_count; i++)
    {
        Position enemy_position = field->getRandomFreePosition();
        if (enemy_position.getX() >= 0 && enemy_position.getX() >= 0)
            field->addEntity(new Enemy, enemy_position);
    }
}

#endif
