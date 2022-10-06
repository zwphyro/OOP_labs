#include "entity.h"

int Entity::getDirection() const
{
	return direction;
}

int Entity::movementDelay() const
{
	if (time_delay == std::chrono::milliseconds(0))
		return 0;
	int movement_delay = 10 - (((std::chrono::steady_clock::now() - previous_movement_time) * 10) / time_delay);
	if (movement_delay <= 0)
		return 0;
	return movement_delay;
}
