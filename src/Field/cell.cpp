#include "cell.h"
#include "./../Event/event.h"

Cell::Cell(Event *event)
{
	_current_event = event;
	_occupied = false;
}

Cell::Cell(const Cell &obj) : _current_event(obj._current_event), _occupied(obj._occupied)
{
}

Cell &Cell::operator=(const Cell &obj)
{
	if (this != &obj)
	{
		_current_event = obj._current_event;
		_occupied = obj._occupied;
	}

	return *this;
}

Cell::~Cell()
{
}

void Cell::setEvent(Event *event)
{
	_current_event = event;
}

const Event *Cell::getEvent() const
{
	return _current_event;
}

bool Cell::isOccupied() const
{
	return _occupied;
}

void Cell::playerStepped()
{
	_occupied = true;
	Event *tmp = _current_event;
	if (_current_event && _current_event->action())
		if (tmp == _current_event)
		{
			delete _current_event;
			_current_event = nullptr;
		}
}

void Cell::enemyStepped()
{
	_occupied = true;
}

void Cell::entityGone()
{
	_occupied = false;
}
