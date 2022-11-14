#ifndef CELL_H
#define CELL_H

class Event;

class Cell
{
public:
	Cell(Event *event = nullptr);
	Cell(const Cell &obj);
	Cell &operator=(const Cell &obj);
	~Cell();

	void setEvent(Event *event);
	const Event *getEvent() const;

	bool isOccupied() const;

	void playerStepped();
	void enemyStepped();

	void entityGone();

private:
	Event *_current_event;
	bool _occupied;
};

#endif
