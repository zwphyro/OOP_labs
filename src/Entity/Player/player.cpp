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
	return Entity::getDirection();
}

int Player::movementDelay() const
{
	return Entity::movementDelay();
}

bool Player::moveRequest(int direction)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: player; Event: recieved request to move;"));
	return Entity::moveRequest(direction);
}

void Player::moveCommit()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: player; Event: movement committed;"));
	return Entity::moveCommit();
}

bool Player::shootRequest()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, _energy >= 3000 ? "Object: player; Event: shoot request was accepted;" : "Object: player; Event: shoot request was rejected;"));
	return _energy >= 3000;
}

int Player::getEnergyRelation() const
{
	return (_energy * 100) / _max_energy;
}

int Player::getProgressRelation() const
{
	return (_progress * 100) / _max_progress;
}

void Player::changeEnergy(int delta_energy)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: player; Event: energy was changed;"));
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
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: player; Event: progress was changed;"));
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
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: player; Event: speed was changed;"));
	if (_time_delay - std::chrono::milliseconds(delta_speed) < std::chrono::milliseconds(150))
	{
		_time_delay = std::chrono::milliseconds(120);
		return;
	}

	_time_delay -= std::chrono::milliseconds(delta_speed);
}
