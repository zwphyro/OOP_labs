#include <cmath>
#include "position.h"
#include "./../Entity/direction.h"

Position::Position(int x, int y) : _x(x), _y(y)
{
}

void Position::setX(int x)
{
    _x = x;
}

void Position::setY(int y)
{
    _y = y;
}

int Position::getX()
{
    return _x;
}

int Position::getY()
{
    return _y;
}

int Position::calculateDistance(Position other_position)
{
    return std::pow(other_position.getX() - _x, 2) + std::pow(other_position.getY() - _y, 2);
}

Position Position::calculateSidePosition(int direction, int max_x, int max_y)
{
    switch (direction)
    {
    case Direction::UP:
        return Position(_x, (_y - 1 + max_y) % max_y);

    case Direction::DOWN:
        return Position(_x, (_y + 1) % max_y);

    case Direction::RIGHT:
        return Position((_x + 1) % max_x, _y);

    case Direction::LEFT:
        return Position((_x - 1 + max_x) % max_x, _y);
    }

    return Position(_x, _y);
}

bool operator==(const Position &pos_1, const Position &pos_2)
{
    return (pos_1._x == pos_2._x) && (pos_1._y == pos_2._y);
}

bool operator!=(const Position &pos_1, const Position &pos_2)
{
    return !(pos_1 == pos_2);
}
