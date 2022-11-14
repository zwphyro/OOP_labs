#ifndef ENTITY_H
#define ENTITY_H

#include <chrono>
#include "./../Logging/observable.h"

typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
typedef std::chrono::milliseconds Milliseconds;

class Entity : public Observable
{
public:
	virtual int getDirection() const;
	virtual int movementDelay() const;

	virtual bool moveRequest(int direction);
	virtual void moveCommit();

	virtual ~Entity() = 0;

protected:
	int _direction;

	TimePoint _previous_movement_time;
	Milliseconds _time_delay;
};

#endif
