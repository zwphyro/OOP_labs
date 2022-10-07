#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>
#include <ctime>

#include <vector>
#include "./../Entity/Player/interactor.h"
#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"
#include "cell.h"
#include "./../Event/event.h"
#include "./../Event/eventfacade.h"
#include "position.h"
#include "./../Entity/entitycontainer.h"

typedef std::vector<EntityContainer> EnemyVector;

class Field
{
	EventFacade *event_facade;

	Cell ***cell_arr;
	int width;
	int height;

	EntityContainer player_container;
	EnemyVector enemys_container;

public:
	Field(int width = 5, int height = 5);
	Field(const Field &obj);
	Field &operator=(const Field &obj);
	Field(Field &&obj);
	Field &operator=(Field &&obj);
	~Field();

	void setEventFacade(EventFacade *event_facade);

	Position getRandomFreePosition();

	void addEntity(Player *entity, Position position);
	void addEntity(Enemy *entity, Position position);

	Cell *getCell(Position position);
	EventFacade &getEventFacade();

	EntityContainer *getPlayerContainer();
	EnemyVector *getEnemysContainer();

	int getWidth() const;
	int getHeight() const;
};

#endif
