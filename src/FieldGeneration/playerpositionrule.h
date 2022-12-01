#ifndef PLAYERPOSITIONRULE_H
#define PLAYERPOSITIONRULE_H

#include "./../Field/field.h"
#include "./../Field/cell.h"
#include "./../Field/position.h"
#include "./../Entity/Player/player.h"

template <int x_position = -1, int y_position = -1>
class PlayerPositionRule
{
public:
    void apply(Field *field);
};

template <int x_position, int y_position>
void PlayerPositionRule<x_position, y_position>::apply(Field *field)
{
    Position player_position;
    if (x_position == -1 || y_position == -1 || field->getCell(Position(x_position, y_position))->isOccupied() || field->getCell(Position(x_position, y_position))->getEvent())
        player_position = field->getRandomFreePosition();
    else
        player_position = Position(x_position, y_position);

    field->addEntity(new Player, player_position);
}

#endif
