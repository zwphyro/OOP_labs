#include "enemycontroller.h"

EnemyController::EnemyController(Field *field) : field(field)
{
    enemys = field->getEnemysContainer();
}

void EnemyController::setField(Field *field)
{
    this->field = field;
    if (field == nullptr)
        enemys = nullptr;
    else
        enemys = field->getEnemysContainer();
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
        new_y = (old_y - 1 + field->getHeight()) % field->getHeight();
        break;
    case Direction::DOWN:
        new_x = old_x;
        new_y = (old_y + 1) % field->getHeight();
        break;
    case Direction::RIGHT:
        new_x = (old_x + 1) % field->getWidth();
        new_y = old_y;
        break;
    case Direction::LEFT:
        new_x = (old_x - 1 + field->getWidth()) % field->getWidth();
        new_y = old_y;
        break;
    }

    return {new_x, new_y};
}

void EnemyController::updateEnemys()
{
    for (int i = 0; i < enemys->size(); i++)
    {
        // find good direction
        int direction = Direction::UP;
        moveEnemy(&enemys->at(i), direction);
    }
}

void EnemyController::moveEnemy(EntityContainer *container, int direction)
{
    if (!container->entity->moveStart(direction))
        return;

    Cell *old_cell = field->getCell(container->position);
    Position new_pos = calculateSidePosition(container->position, direction);
    // calculate new position
    Cell *new_cell = field->getCell(new_pos);
    if (new_cell->isOccupied())
        return;
    container->position = new_pos;
    old_cell->entityGone();
    new_cell->enemyStepped();
    container->entity->moveCommited();
}
