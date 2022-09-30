#ifndef PLAYER_H
#define PLAYER_H

#include "playercontroller.h"
#include "./../entity.h"

class Player : public Entity {
	PlayerController *controller;
	int energy;
	int max_energy;
	int progress;
	int max_progress;

public:
	Player();
	~Player() {}

	void setController(PlayerController *controller);

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