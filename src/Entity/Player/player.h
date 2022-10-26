#ifndef PLAYER_H
#define PLAYER_H

#include "./../entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	int getDirection() const;
	int movementDelay() const;

	bool moveRequest(int direction);
	void moveCommit();

	bool shootRequest();

	int getEnergyRelation() const;
	int getProgressRelation() const;

	void changeEnergy(int delta_energy = 1);
	void changeProgress(int delta_progress = -1);
	void changeSpeed(int delta_speed = 1);

private:
	int _energy;
	int _max_energy;
	int _progress;
	int _max_progress;
};

#endif
