#include "cell.h"

Cell::Cell(Event *event)
{
	current_event = event;
	occupied = false;
}

Cell::Cell(const Cell &obj) : current_event(obj.current_event), occupied(obj.occupied)
{
}

Cell &Cell::operator=(const Cell &obj)
{
	if (this != &obj)
	{
		current_event = obj.current_event;
		occupied = obj.occupied;
	}

	return *this;
}

Cell::~Cell()
{
	// if (current_event) delete current_event;
}

void Cell::setEvent(Event *event)
{
	// if (current_event) delete current_event;
	current_event = event;
}

const Event *Cell::getEvent()
{
	return current_event;
}

bool Cell::isOccupied()
{
	return occupied;
}

void Cell::playerStepped()
{
	occupied = true;
	Event *tmp = current_event;
	if (current_event && current_event->action())
	{
		if (tmp == current_event)
		{
			// delete current_event;
			current_event = nullptr;
		}
	}
}

void Cell::enemyStepped()
{
	occupied = true;
}

void Cell::entityGone()
{
	occupied = false;
}
