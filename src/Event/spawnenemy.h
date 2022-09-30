#ifndef SPAWNENEMY_H
#define SPAWNENEMY_H

#include "fieldevent.h"
#include "./../Entity/enemy.h"

class SpawnEnemy: public FieldEvent {

public:
	SpawnEnemy(Field *field = nullptr);
	SpawnEnemy(const SpawnEnemy& obj);
	SpawnEnemy& operator=(const SpawnEnemy& obj);

	bool action();

};

#endif
