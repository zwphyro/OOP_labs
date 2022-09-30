#ifndef POSITION_H
#define POSITION_H

struct Position {
	int x;
	int y;
	
	friend bool operator==(const Position& pos_1, const Position& pos_2) {
		return (pos_1.x == pos_2.x) && (pos_1.y == pos_2.y);
	}

};


#endif
