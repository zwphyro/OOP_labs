#include "player.h"

Player::Player()
{
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	direction = DOWN;

	time_delay = std::chrono::milliseconds(300);
	previous_movement_time = std::chrono::steady_clock::now() - time_delay;

	energy = 0;
	max_energy = 1000;
	progress = 500;
	max_progress = 1000;
}

Player::~Player()
{
}

bool Player::shootStart()
{
	return energy >= 100;
}

int Player::getEnergyRelation() const
{
	return (energy * 100) / max_energy;
}

int Player::getProgressRelation() const
{
	return (progress * 100) / max_progress;
}

void Player::changeEnergy(int delta_energy)
{
	if (energy + delta_energy > max_energy)
	{
		energy = max_energy;
		return;
	}
	else if (energy + delta_energy < 0)
	{
		energy = 0;
		return;
	}

	energy += delta_energy;
}

void Player::changeProgress(int delta_progress)
{
	if (progress + delta_progress > max_progress)
	{
		progress = max_progress;
		return;
	}
	else if (progress + delta_progress < 0)
	{
		progress = 0;
		return;
	}

	progress += delta_progress;
}

void Player::changeSpeed(int delta_speed)
{
	if (time_delay - std::chrono::milliseconds(delta_speed) < std::chrono::milliseconds(150))
	{
		time_delay = std::chrono::milliseconds(120);
		return;
	}

	time_delay -= std::chrono::milliseconds(delta_speed);
}
