#include <cmath>
#include "entity.h"

Entity::~Entity()
{
}

int Entity::getDirection() const
{
	return _direction;
}

int Entity::movementDelay() const
{
	if (_time_delay == std::chrono::milliseconds(0))
		return 0;
	int movement_delay = 11 - (((std::chrono::steady_clock::now() - _previous_movement_time) * 11) / _time_delay);
	if (movement_delay <= 0)
		return 0;
	return movement_delay;
}

bool Entity::moveRequest(int move_direction)
{
	if (std::chrono::steady_clock::now() - _previous_movement_time < _time_delay)
		return false;

	_direction = move_direction;
	return true;
}

void Entity::moveCommit()
{
	_previous_movement_time = std::chrono::steady_clock::now();
}
