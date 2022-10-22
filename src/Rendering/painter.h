#ifndef PAINTER_H
#define PAINTER_H

#include <chrono>
#include "./../Field/position.h"

class Field;

class Painter
{
public:
	Painter();
	~Painter();

	void drawField(const Field *field);

private:
	std::chrono::time_point<std::chrono::steady_clock> _start;
	int _frame_no;

	void drawEmptyCell(Position pos);
	void drawAddProgress(Position pos);
	void drawSpawnEnemy(Position pos);
	void drawAddEnergy(Position pos);
	void drawTeleportPlayer(Position pos);

	void drawPixel(Position cell_pos, Position pixel_pos, int color_scheme, int h_movement_delay, int v_movement_delay, int rotation = 0);
	void drawPlayer(Position pos, int direction, int movement_delay);
	void drawEnemy(Position pos, int direction, int movement_delay);

	void drawYouWin();
	void drawYouLose();

	void drawInterface(int energy, int progress);
};

#endif
