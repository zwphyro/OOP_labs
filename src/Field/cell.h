#ifndef CELL_H
#define CELL_H

#include "./../Event/event.h"

class Cell
{
	Event *current_event;
	bool occupied;

public:
	Cell(Event *event = nullptr);
	Cell(const Cell &obj);
	Cell &operator=(const Cell &obj);
	~Cell();

	void setEvent(Event *event);
	const Event *getEvent();

	bool isOccupied();

	void playerStepped();
	void enemyStepped();
	void entityGone();
};

#endif
