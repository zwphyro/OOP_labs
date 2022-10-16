#ifndef ENTITY_H
#define ENTITY_H

#include <chrono>

typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
typedef std::chrono::milliseconds Milliseconds;

class Entity
{
public:
	int getDirection() const;
	int movementDelay() const;

	bool moveStart(int direction);
	void moveCommited();

	virtual ~Entity() {}

protected:
	int _direction;

	TimePoint _previous_movement_time;
	Milliseconds _time_delay;
};

#endif
