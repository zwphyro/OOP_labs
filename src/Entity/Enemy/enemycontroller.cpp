#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "enemycontroller.h"
#include "./../enemy.h"
#include "./../../Field/field.h"
#include "./../Player/interactor.h"
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
    int delta_x = (player_position.x - enemy_position.x) / std::abs(player_position.x - enemy_position.x);
    int delta_y = (player_position.y - enemy_position.y) / std::abs(player_position.y - enemy_position.y);
    std::pair<int, int> directions;
    directions.first = delta_x > 0 ? Direction::RIGHT : Direction::LEFT;
    directions.second = delta_y > 0 ? Direction::DOWN : Direction::UP;
    int horizontal_movement = std::pow(player_position.x - (enemy_position.x + delta_x), 2) + std::pow(player_position.y - enemy_position.y, 2);
    int vertical_movement = std::pow(player_position.y - (enemy_position.y + delta_y), 2) + std::pow(player_position.x - enemy_position.x, 2);
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
        Position(player_position.x + width, player_position.y),
        Position(player_position.x - width, player_position.y),
        Position(player_position.x, player_position.y + height),
        Position(player_position.x, player_position.y - height),
    };

    Position optimal_position = positions[0];
    int min_distance = std::pow(positions[0].x - enemy_position.x, 2) + std::pow(positions[0].y - enemy_position.y, 2);
    int distance;

    for (int i = 0; i < 5; i++)
    {
        distance = std::pow(positions[i].x - enemy_position.x, 2) + std::pow(positions[i].y - enemy_position.y, 2);
        if (distance < min_distance)
        {
            min_distance = distance;
            optimal_position = positions[i];
        }
    }

    return optimal_position;
}

Position EnemyController::calculateSidePosition(Position position, int direction)
{
    int old_x = position.x;
    int old_y = position.y;
    int new_x, new_y;

    switch (direction)
    {
    case Direction::UP:
        new_x = old_x;
        new_y = (old_y - 1 + _field->getHeight()) % _field->getHeight();
        break;
    case Direction::DOWN:
        new_x = old_x;
        new_y = (old_y + 1) % _field->getHeight();
        break;
    case Direction::RIGHT:
        new_x = (old_x + 1) % _field->getWidth();
        new_y = old_y;
        break;
    case Direction::LEFT:
        new_x = (old_x - 1 + _field->getWidth()) % _field->getWidth();
        new_y = old_y;
        break;
    }

    return {new_x, new_y};
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
    Position new_pos = calculateSidePosition(container->position, direction);
    Cell *new_cell = _field->getCell(new_pos);
    if (new_cell->isOccupied())
        return;
    container->position = new_pos;
    old_cell->entityGone();
    new_cell->enemyStepped();
    container->entity->moveCommited();
}
