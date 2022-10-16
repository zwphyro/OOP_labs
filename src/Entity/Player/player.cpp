#include "player.h"
#include "interactor.h"
#include "./../direction.h"

Player::Player()
{

	_direction = Direction::DOWN;

	_time_delay = std::chrono::milliseconds(300);
	_previous_movement_time = std::chrono::steady_clock::now() - _time_delay;

	_energy = 0;
	_max_energy = 1000;
	_progress = 500;
	_max_progress = 1000;
}

Player::~Player()
{
}

bool Player::shootStart()
{
	return _energy >= 100;
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
	if (_time_delay - std::chrono::milliseconds(delta_speed) < std::chrono::milliseconds(150))
	{
		_time_delay = std::chrono::milliseconds(120);
		return;
	}

	_time_delay -= std::chrono::milliseconds(delta_speed);
}
