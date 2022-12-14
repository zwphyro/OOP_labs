#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	Position(int x = -1, int y = -1);

	void setX(int x);
	void setY(int y);

	int getX();
	int getY();

	int calculateDistance(Position other_position);
	Position calculateSidePosition(int direction, int max_x, int max_y);

	friend bool operator==(const Position &pos_1, const Position &pos_2);
	friend bool operator!=(const Position &pos_1, const Position &pos_2);

private:
	int _x;
	int _y;
};

#endif
