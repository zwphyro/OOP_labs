#ifndef ENTITY_H
#define ENTITY_H

#include <chrono>
#include <cmath>

typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
typedef std::chrono::milliseconds Milliseconds;

class Entity
{
protected:
	int direction;

	TimePoint previous_movement_time;
	Milliseconds time_delay;

public:
	int getDirection() const;
	int movementDelay() const;

	virtual ~Entity() {}
};

#endif
