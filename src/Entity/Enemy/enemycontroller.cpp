#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "enemycontroller.h"
#include "./../enemy.h"
#include "./../../Field/field.h"
#include "./../direction.h"
#include "./../../Field/cell.h"

EnemyController::EnemyController(Field *field) : _field(field)
{
    _enemys = field->getEnemysContainer();
}

void EnemyController::setField(Field *field)
{
    _field = field;
    if (field == nullptr)
        _enemys = nullptr;
    else
        _enemys = field->getEnemysContainer();
}

int EnemyController::calculateDirection(Position player_position, Position enemy_position)
{
    int delta_x = (player_position.getX() - enemy_position.getX()) > 0 ? 1 : -1;
    int delta_y = (player_position.getY() - enemy_position.getY()) > 0 ? 1 : -1;
    std::pair<int, int> directions;
    directions.first = delta_x > 0 ? Direction::RIGHT : Direction::LEFT;
    directions.second = delta_y > 0 ? Direction::DOWN : Direction::UP;

    int horizontal_movement = player_position.calculateDistance(Position(enemy_position.getX() + delta_x, enemy_position.getY()));
    int vertical_movement = player_position.calculateDistance(Position(enemy_position.getX(), enemy_position.getY() + delta_y));
    int optimal_direction = horizontal_movement < vertical_movement ? directions.first : directions.second;

    srand(time(nullptr));

    if (horizontal_movement == vertical_movement)
        if (rand() % 2)
            optimal_direction = directions.first;
        else
            optimal_direction = directions.second;

    return optimal_direction;
}

Position EnemyController::calculateOptimalPlayerPosition(Position player_position, Position enemy_position, int width, int height)
{
    Position positions[5] = {
        player_position,
        Position(player_position.getX() + width, player_position.getY()),
        Position(player_position.getY() - width, player_position.getY()),
        Position(player_position.getX(), player_position.getY() + height),
        Position(player_position.getX(), player_position.getY() - height),
    };

    Position optimal_position = positions[0];
    int min_distance = enemy_position.calculateDistance(positions[0]);
    int distance;

    for (int i = 0; i < 5; i++)
    {
        distance = enemy_position.calculateDistance(positions[i]);
        if (distance < min_distance)
        {
            min_distance = distance;
            optimal_position = positions[i];
        }
    }

    return optimal_position;
}

void EnemyController::updateEnemys()
{
    for (int i = 0; i < _enemys->size(); i++)
    {
        int direction = calculateDirection(calculateOptimalPlayerPosition(_field->getPlayerContainer()->position, _enemys->at(i).position, _field->getWidth(), _field->getHeight()), _enemys->at(i).position);
        moveEnemy(&_enemys->at(i), direction);
    }
}

void EnemyController::moveEnemy(EntityContainer *container, int direction)
{
    if (!container->entity->moveStart(direction))
        return;

    Cell *old_cell = _field->getCell(container->position);
    Position new_pos = container->position.calculateSidePosition(direction, _field->getWidth(), _field->getHeight());
    Cell *new_cell = _field->getCell(new_pos);
    if (new_cell->isOccupied())
        return;
    container->position = new_pos;
    old_cell->entityGone();
    new_cell->enemyStepped();
    container->entity->moveCommited();
}
