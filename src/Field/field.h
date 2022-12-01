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
class OptionsParameters;

typedef std::vector<EntityContainer> EnemyVector;
typedef std::vector<Position> WallsPositions;

class Field : public Observable
{
public:
	Field(const OptionsParameters *options);
	// Field(Field &&obj);
	// Field &operator=(Field &&obj);
	// Field(const Field &obj);
	// Field &operator=(const Field &obj);
	~Field();

	Position getRandomFreePosition();

	void addEntity(Enemy *entity, Position position);
	void addEntity(Player *entity, Position position);
	void addWall(Position position);

	Cell *getCell(Position position);
	Cell getCell(Position position) const;
	EventFacade *getEventFacade();

	EntityContainer *getPlayerContainer();
	const EntityContainer *getPlayerContainer() const;
	EnemyVector *getEnemysContainer();
	const EnemyVector getEnemysContainer() const;
	WallsPositions *getWallsPositions();
	const WallsPositions getWallsPositions() const;

	int getGameStatus() const;

	int getWidth() const;
	int getHeight() const;

private:
	EventFacade *_event_facade;

	Cell ***_cell_arr;
	int _width;
	int _height;

	EntityContainer _player_container;
	EnemyVector _enemys_container;
	WallsPositions _walls_positions;
};

#endif
