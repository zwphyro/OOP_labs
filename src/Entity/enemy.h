#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	virtual int getDirection() const;
	virtual int movementDelay() const;

	virtual bool moveStart(int direction);
	virtual void moveCommited();
};

#endif
