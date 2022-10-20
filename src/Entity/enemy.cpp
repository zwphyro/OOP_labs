#include "enemy.h"
#include "./direction.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

Enemy::Enemy()
{

	_direction = Direction::DOWN;

	_time_delay = std::chrono::milliseconds(900);
	_previous_movement_time = std::chrono::steady_clock::now() - _time_delay;
}

Enemy::~Enemy()
{
}

int Enemy::getDirection() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "enemy direction requested"));
	return Entity::getDirection();
}

int Enemy::movementDelay() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "enemy movement delay requested"));
	return Entity::movementDelay();
}

bool Enemy::moveStart(int direction)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "enemy move requested"));
	return Entity::moveStart(direction);
}

void Enemy::moveCommited()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "enemy move commited"));
	return Entity::moveCommited();
}
