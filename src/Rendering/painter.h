#ifndef PAINTER_H
#define PAINTER_H

#include <ncurses.h>
#include <chrono>
#include "./../Field/position.h"
#include "./../Field/field.h"
#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"
#include "./../Entity/entitycontainer.h"
#include "./../Event/addenergy.h"
#include "./../Event/addprogress.h"
#include "./../Event/spawnenemy.h"

class Painter {
	std::chrono::time_point<std::chrono::steady_clock> start;
	int frame_no;

	void drawEmptyCell(Position pos);
	void drawAddProgress(Position pos);
	void drawSpawnEnemy(Position pos);
	void drawAddEnergy(Position pos);

	void drawPixel(Position cell_pos, Position pixel_pos, int color_scheme, int h_movement_delay, int v_movement_delay, int rotation = 0);
	void drawPlayer(Position pos, int direction, int movement_delay);
	void drawEnemy(Position pos, int direction, int movement_delay);
	
	void drawInterface(int energy, int progress);

public:
	Painter();
	~Painter();
	
	void drawField(const Field* field);

};

#endif
