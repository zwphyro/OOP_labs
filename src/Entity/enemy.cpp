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
	return Entity::getDirection();
}

int Enemy::movementDelay() const
{
	return Entity::movementDelay();
}

bool Enemy::moveRequest(int direction)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: enemy; Event: recieved request to move;"));
	return Entity::moveRequest(direction);
}

void Enemy::moveCommit()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: enemy; Event: movement committed;"));
	return Entity::moveCommit();
}
