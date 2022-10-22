#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include "position.h"
#include "./../Entity/entitycontainer.h"
#include "./../Logging/observable.h"

class Player;
class Enemy;
class Cell;
class Event;
class EventFacade;

typedef std::vector<EntityContainer> EnemyVector;

class Field : public Observable
{
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
	Cell getCell(Position position) const;
	EventFacade &getEventFacade();

	EntityContainer *getPlayerContainer();
	const EntityContainer *getPlayerContainer() const;
	EnemyVector *getEnemysContainer();
	const EnemyVector getEnemysContainer() const;

	int getWidth() const;
	int getHeight() const;

private:
	EventFacade *_event_facade;

	Cell ***_cell_arr;
	int _width;
	int _height;

	EntityContainer _player_container;
	EnemyVector _enemys_container;
};

#endif
