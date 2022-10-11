#include "enemy.h"
#include "./Player/interactor.h"

Enemy::Enemy()
{

	_direction = Direction::DOWN;

	_time_delay = std::chrono::milliseconds(700);
	_previous_movement_time = std::chrono::steady_clock::now() - _time_delay;
}

Enemy::~Enemy()
{
}
