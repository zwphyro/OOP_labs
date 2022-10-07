#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "./../enemy.h"
#include "./../../Field/field.h"

class EnemyController
{
    Field *field;
    EnemyVector *enemys;

public:
    EnemyController(Field *field = nullptr);

    void setField(Field *field);

    Position calculateSidePosition(Position position, int direction);

    void updateEnemys();
    void moveEnemy(EntityContainer *container, int direction);
};

#endif
