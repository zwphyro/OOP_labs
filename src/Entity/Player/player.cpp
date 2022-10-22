#include "player.h"
#include "interactor.h"
#include "./../direction.h"
#include "./../../Logging/logmessage.h"
#include "./../../Logging/loglevel.h"

Player::Player()
{
	_direction = Direction::DOWN;

	_time_delay = std::chrono::milliseconds(300);
	_previous_movement_time = std::chrono::steady_clock::now() - _time_delay;

	_energy = 0;
	_max_energy = 30000;
	_progress = 15000;
	_max_progress = 30000;
}

Player::~Player()
{
}

int Player::getDirection() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player direction requested"));
	return Entity::getDirection();
}

int Player::movementDelay() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player movement delay requested"));
	return Entity::movementDelay();
}

bool Player::moveStart(int direction)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player move requested"));
	return Entity::moveStart(direction);
}

void Player::moveCommited()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player move commited"));
	return Entity::moveCommited();
}

bool Player::shootStart()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, _energy >= 3000 ? "player shoot triggered" : "player shoot rejected"));
	return _energy >= 3000;
}

int Player::getEnergyRelation() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player energy relation requested"));
	return (_energy * 100) / _max_energy;
}

int Player::getProgressRelation() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player progress relation requested"));
	return (_progress * 100) / _max_progress;
}

void Player::changeEnergy(int delta_energy)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player energy change requested"));
	if (_energy + delta_energy > _max_energy)
	{
		_energy = _max_energy;
		return;
	}
	else if (_energy + delta_energy < 0)
	{
		_energy = 0;
		return;
	}

	_energy += delta_energy;
}

void Player::changeProgress(int delta_progress)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player progress change requested"));
	if (_progress + delta_progress > _max_progress)
	{
		_progress = _max_progress;
		return;
	}
	else if (_progress + delta_progress < 0)
	{
		_progress = 0;
		return;
	}

	_progress += delta_progress;
}

void Player::changeSpeed(int delta_speed)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "player speed change requested"));
	if (_time_delay - std::chrono::milliseconds(delta_speed) < std::chrono::milliseconds(150))
	{
		_time_delay = std::chrono::milliseconds(120);
		return;
	}

	_time_delay -= std::chrono::milliseconds(delta_speed);
}
