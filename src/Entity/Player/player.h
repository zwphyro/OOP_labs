#ifndef PLAYER_H
#define PLAYER_H

#include "interactor.h"
#include "./../entity.h"

class Player : public Entity
{
	int energy;
	int max_energy;
	int progress;
	int max_progress;

public:
	Player();
	~Player();

	bool shootStart();

	bool moveStart(int direction);
	void moveCommited();

	int getEnergyRelation() const;
	int getProgressRelation() const;

	void changeEnergy(int delta_energy = 1);
	void changeProgress(int delta_progress = -1);
	void changeSpeed(int delta_speed = 1);
};

#endif
