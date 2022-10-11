#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include <vector>
#include "./../entitycontainer.h"
typedef std::vector<EntityContainer> EnemyVector;

class Field;
class Position;

class EnemyController
{
public:
    EnemyController(Field *field = nullptr);

    void setField(Field *field);

    void updateEnemys();

private:
    Field *_field;
    EnemyVector *_enemys;
    Position calculateOptimalPlayerPosition(Position player_position, Position enemy_position, int width, int height);
    Position calculateSidePosition(Position position, int direction);
    void moveEnemy(EntityContainer *container, int direction);
    int calculateDirection(Position player_position, Position enemy_position);
};

#endif
