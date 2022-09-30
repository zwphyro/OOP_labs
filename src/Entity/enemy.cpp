#include "enemy.h"

Enemy::Enemy()
{
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	direction = DOWN;

	time_delay = std::chrono::milliseconds(700);
	previous_movement_time = std::chrono::steady_clock::now() - time_delay;
}

Enemy::~Enemy()
{
}
