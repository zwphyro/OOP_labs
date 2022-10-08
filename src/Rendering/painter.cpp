#include "painter.h"

#define CELL_WIDTH 20
#define CELL_HEIGHT 10

Painter::Painter()
{
	initscr();
	noecho();
	raw();
	halfdelay(1);
	keypad(stdscr, true);
	start = std::chrono::steady_clock::now();
	frame_no = 1;
}

Painter::~Painter()
{
	cbreak();
	echo();
	endwin();
}

void Painter::drawEmptyCell(Position pos)
{
	for (int i = (CELL_HEIGHT + 1) * pos.y; i < (CELL_HEIGHT + 1) * (pos.y + 1) - 1; i++)
		for (int j = (CELL_WIDTH + 2) * pos.x; j < (CELL_WIDTH + 2) * (pos.x + 1) - 2; j++)
			mvwaddch(stdscr, i, j, '*' | A_DIM);
}

void Painter::drawAddProgress(Position pos)
{
	start_color();
	init_pair(9, COLOR_BLACK, COLOR_MAGENTA);

	drawPixel(pos, {1, 1}, 9, 0, 0);
	drawPixel(pos, {1, 4}, 9, 0, 0);
	drawPixel(pos, {2, 7}, 9, 0, 0);
	drawPixel(pos, {3, 3}, 9, 0, 0);
	drawPixel(pos, {4, 7}, 9, 0, 0);
	drawPixel(pos, {5, 4}, 9, 0, 0);
	drawPixel(pos, {5, 5}, 9, 0, 0);
	drawPixel(pos, {6, 3}, 9, 0, 0);
	drawPixel(pos, {6, 4}, 9, 0, 0);
	drawPixel(pos, {6, 5}, 9, 0, 0);
	drawPixel(pos, {6, 6}, 9, 0, 0);
	drawPixel(pos, {7, 3}, 9, 0, 0);
	drawPixel(pos, {7, 4}, 9, 0, 0);
	drawPixel(pos, {7, 5}, 9, 0, 0);
	drawPixel(pos, {7, 6}, 9, 0, 0);
	drawPixel(pos, {8, 4}, 9, 0, 0);
	drawPixel(pos, {8, 5}, 9, 0, 0);
}

void Painter::drawAddEnergy(Position pos)
{
	start_color();
	init_pair(3, COLOR_BLACK, COLOR_BLUE);

	drawPixel(pos, {1, 1}, 3, 0, 0);
	drawPixel(pos, {1, 4}, 3, 0, 0);
	drawPixel(pos, {2, 7}, 3, 0, 0);
	drawPixel(pos, {3, 3}, 3, 0, 0);
	drawPixel(pos, {4, 7}, 3, 0, 0);
	drawPixel(pos, {5, 4}, 3, 0, 0);
	drawPixel(pos, {5, 5}, 3, 0, 0);
	drawPixel(pos, {6, 3}, 3, 0, 0);
	drawPixel(pos, {6, 4}, 3, 0, 0);
	drawPixel(pos, {6, 5}, 3, 0, 0);
	drawPixel(pos, {6, 6}, 3, 0, 0);
	drawPixel(pos, {7, 3}, 3, 0, 0);
	drawPixel(pos, {7, 4}, 3, 0, 0);
	drawPixel(pos, {7, 5}, 3, 0, 0);
	drawPixel(pos, {7, 6}, 3, 0, 0);
	drawPixel(pos, {8, 4}, 3, 0, 0);
	drawPixel(pos, {8, 5}, 3, 0, 0);
}

void Painter::drawSpawnEnemy(Position pos)
{
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);

	drawPixel(pos, {0, 4}, 3, 0, 0);
	drawPixel(pos, {1, 4}, 3, 0, 0);
	drawPixel(pos, {1, 6}, 3, 0, 0);
	drawPixel(pos, {2, 1}, 3, 0, 0);
	drawPixel(pos, {2, 4}, 3, 0, 0);
	drawPixel(pos, {3, 1}, 3, 0, 0);
	drawPixel(pos, {3, 3}, 3, 0, 0);
	drawPixel(pos, {3, 4}, 3, 0, 0);
	drawPixel(pos, {3, 6}, 3, 0, 0);
	drawPixel(pos, {4, 3}, 3, 0, 0);
	drawPixel(pos, {4, 4}, 3, 0, 0);
	drawPixel(pos, {4, 5}, 3, 0, 0);
	drawPixel(pos, {4, 6}, 3, 0, 0);
	drawPixel(pos, {4, 7}, 3, 0, 0);
	drawPixel(pos, {5, 2}, 3, 0, 0);
	drawPixel(pos, {5, 3}, 3, 0, 0);
	drawPixel(pos, {5, 4}, 3, 0, 0);
	drawPixel(pos, {5, 5}, 3, 0, 0);
	drawPixel(pos, {5, 6}, 3, 0, 0);
	drawPixel(pos, {5, 7}, 3, 0, 0);
	drawPixel(pos, {6, 2}, 3, 0, 0);
	drawPixel(pos, {6, 3}, 3, 0, 0);
	drawPixel(pos, {6, 4}, 1, 0, 0);
	drawPixel(pos, {6, 5}, 3, 0, 0);
	drawPixel(pos, {6, 6}, 1, 0, 0);
	drawPixel(pos, {6, 7}, 3, 0, 0);
	drawPixel(pos, {7, 2}, 3, 0, 0);
	drawPixel(pos, {7, 3}, 3, 0, 0);
	drawPixel(pos, {7, 4}, 3, 0, 0);
	drawPixel(pos, {7, 5}, 3, 0, 0);
	drawPixel(pos, {7, 6}, 3, 0, 0);
	drawPixel(pos, {7, 7}, 3, 0, 0);
	drawPixel(pos, {8, 3}, 3, 0, 0);
	drawPixel(pos, {8, 4}, 3, 0, 0);
	drawPixel(pos, {8, 5}, 3, 0, 0);
	drawPixel(pos, {8, 6}, 3, 0, 0);
}

void Painter::drawTeleportPlayer(Position pos)
{
	start_color();
	init_pair(3, COLOR_BLACK, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_RED);

	drawPixel(pos, {1, 3}, 3, 0, 0);
	drawPixel(pos, {1, 4}, 3, 0, 0);
	drawPixel(pos, {1, 5}, 3, 0, 0);
	drawPixel(pos, {1, 6}, 3, 0, 0);
	drawPixel(pos, {2, 2}, 4, 0, 0);
	drawPixel(pos, {2, 3}, 4, 0, 0);
	drawPixel(pos, {2, 6}, 3, 0, 0);
	drawPixel(pos, {2, 7}, 3, 0, 0);
	drawPixel(pos, {3, 2}, 4, 0, 0);
	drawPixel(pos, {3, 3}, 4, 0, 0);
	drawPixel(pos, {3, 6}, 3, 0, 0);
	drawPixel(pos, {3, 7}, 3, 0, 0);
	drawPixel(pos, {4, 2}, 4, 0, 0);
	drawPixel(pos, {4, 7}, 3, 0, 0);
	drawPixel(pos, {5, 2}, 4, 0, 0);
	drawPixel(pos, {5, 7}, 3, 0, 0);
	drawPixel(pos, {6, 2}, 4, 0, 0);
	drawPixel(pos, {6, 3}, 4, 0, 0);
	drawPixel(pos, {6, 6}, 3, 0, 0);
	drawPixel(pos, {6, 7}, 3, 0, 0);
	drawPixel(pos, {7, 2}, 4, 0, 0);
	drawPixel(pos, {7, 3}, 4, 0, 0);
	drawPixel(pos, {7, 6}, 3, 0, 0);
	drawPixel(pos, {7, 7}, 3, 0, 0);
	drawPixel(pos, {8, 3}, 4, 0, 0);
	drawPixel(pos, {8, 4}, 4, 0, 0);
	drawPixel(pos, {8, 5}, 4, 0, 0);
	drawPixel(pos, {8, 6}, 4, 0, 0);
}

void Painter::drawPixel(Position cell_pos, Position pixel_pos, int color_scheme, int h_movement_delay, int v_movement_delay, int rotation)
{
	mvwaddch(stdscr, (CELL_HEIGHT + 1) * cell_pos.y + pixel_pos.x + h_movement_delay, (CELL_WIDTH + 2) * cell_pos.x + (CELL_WIDTH - 1) * rotation + (1 - rotation * 2) * (pixel_pos.y * 2) + v_movement_delay * 2, ' ' | COLOR_PAIR(color_scheme));
	mvwaddch(stdscr, (CELL_HEIGHT + 1) * cell_pos.y + pixel_pos.x + h_movement_delay, (CELL_WIDTH + 2) * cell_pos.x + (CELL_WIDTH - 1) * rotation + (1 - rotation * 2) * (pixel_pos.y * 2 + 1) + v_movement_delay * 2, ' ' | COLOR_PAIR(color_scheme));
}

void Painter::drawPlayer(Position pos, int direction, int movement_delay)
{
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

	if (direction == DOWN)
		movement_delay = -movement_delay;

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);

	if (direction == DOWN || direction == UP)
	{
		drawPixel(pos, {0, 2}, 1, movement_delay, 0);
		drawPixel(pos, {0, 3}, 1, movement_delay, 0);
		drawPixel(pos, {0, 5}, 1, movement_delay, 0);
		drawPixel(pos, {0, 6}, 1, movement_delay, 0);
		drawPixel(pos, {1, 3}, 1, movement_delay, 0);
		drawPixel(pos, {1, 4}, 1, movement_delay, 0);
		drawPixel(pos, {1, 6}, 1, movement_delay, 0);
		drawPixel(pos, {1, 7}, 1, movement_delay, 0);
		drawPixel(pos, {2, 2}, 1, movement_delay, 0);
		drawPixel(pos, {2, 3}, 1, movement_delay, 0);
		drawPixel(pos, {2, 7}, 1, movement_delay, 0);
		drawPixel(pos, {2, 8}, 1, movement_delay, 0);
		drawPixel(pos, {3, 2}, 1, movement_delay, 0);
		drawPixel(pos, {3, 4}, 1, movement_delay, 0);
		drawPixel(pos, {3, 6}, 1, movement_delay, 0);
		drawPixel(pos, {3, 8}, 1, movement_delay, 0);
		drawPixel(pos, {4, 2}, 1, movement_delay, 0);
		drawPixel(pos, {4, 4}, 2, movement_delay, 0);
		drawPixel(pos, {4, 6}, 2, movement_delay, 0);
		drawPixel(pos, {4, 8}, 1, movement_delay, 0);
		drawPixel(pos, {5, 1}, 3, movement_delay, 0);
		drawPixel(pos, {5, 2}, 3, movement_delay, 0);
		drawPixel(pos, {5, 3}, 3, movement_delay, 0);
		drawPixel(pos, {5, 7}, 1, movement_delay, 0);
		drawPixel(pos, {5, 8}, 1, movement_delay, 0);
		drawPixel(pos, {6, 0}, 3, movement_delay, 0);
		drawPixel(pos, {6, 1}, 3, movement_delay, 0);
		drawPixel(pos, {6, 2}, 3, movement_delay, 0);
		drawPixel(pos, {6, 3}, 3, movement_delay, 0);
		drawPixel(pos, {6, 4}, 3, movement_delay, 0);
		drawPixel(pos, {6, 5}, 1, movement_delay, 0);
		drawPixel(pos, {6, 6}, 1, movement_delay, 0);
		drawPixel(pos, {6, 7}, 1, movement_delay, 0);
		drawPixel(pos, {7, 2}, 3, movement_delay, 0);
		drawPixel(pos, {7, 3}, 3, movement_delay, 0);
		drawPixel(pos, {7, 4}, 3, movement_delay, 0);
		drawPixel(pos, {7, 5}, 3, movement_delay, 0);
		drawPixel(pos, {7, 6}, 3, movement_delay, 0);
		drawPixel(pos, {7, 8}, 1, movement_delay, 0);
		drawPixel(pos, {8, 4}, 1, movement_delay, 0);
		drawPixel(pos, {8, 5}, 3, movement_delay, 0);
		drawPixel(pos, {8, 7}, 1, movement_delay, 0);
		drawPixel(pos, {8, 8}, 1, movement_delay, 0);
		drawPixel(pos, {9, 3}, 1, movement_delay, 0);
		drawPixel(pos, {9, 4}, 1, movement_delay, 0);

		return;
	}

	int rotation = 0;
	if (direction == RIGHT)
	{
		movement_delay = -movement_delay;
		rotation = 1;
	}

	drawPixel(pos, {0, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 1}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 0}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 1}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 0}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 1}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 2}, 2, 0, movement_delay, rotation);
	drawPixel(pos, {4, 4}, 2, 0, movement_delay, rotation);
	drawPixel(pos, {4, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {5, 1}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {5, 5}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {5, 6}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {5, 7}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {5, 8}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {6, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 4}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {6, 5}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {6, 6}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {6, 7}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {6, 8}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {6, 9}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 3}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {7, 4}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {7, 5}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {7, 6}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {7, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 8}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 4}, 3, 0, movement_delay, rotation);
	drawPixel(pos, {8, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {9, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {9, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {9, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {9, 6}, 1, 0, movement_delay, rotation);
}

void Painter::drawEnemy(Position pos, int direction, int movement_delay)
{
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

	if (direction == DOWN)
		movement_delay = -movement_delay;

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_RED);

	if (direction == DOWN || direction == UP)
	{
		drawPixel(pos, {0, 3}, 1, movement_delay, 0);
		drawPixel(pos, {0, 4}, 1, movement_delay, 0);
		drawPixel(pos, {0, 5}, 1, movement_delay, 0);
		drawPixel(pos, {0, 6}, 1, movement_delay, 0);
		drawPixel(pos, {0, 7}, 1, movement_delay, 0);
		drawPixel(pos, {0, 8}, 1, movement_delay, 0);
		drawPixel(pos, {1, 2}, 1, movement_delay, 0);
		drawPixel(pos, {1, 3}, 1, movement_delay, 0);
		drawPixel(pos, {1, 4}, 1, movement_delay, 0);
		drawPixel(pos, {1, 5}, 1, movement_delay, 0);
		drawPixel(pos, {1, 6}, 1, movement_delay, 0);
		drawPixel(pos, {2, 2}, 1, movement_delay, 0);
		drawPixel(pos, {2, 3}, 1, movement_delay, 0);
		drawPixel(pos, {2, 4}, 1, movement_delay, 0);
		drawPixel(pos, {2, 5}, 1, movement_delay, 0);
		drawPixel(pos, {2, 6}, 1, movement_delay, 0);
		drawPixel(pos, {2, 7}, 1, movement_delay, 0);
		drawPixel(pos, {3, 2}, 1, movement_delay, 0);
		drawPixel(pos, {3, 3}, 4, movement_delay, 0);
		drawPixel(pos, {3, 4}, 5, movement_delay, 0);
		drawPixel(pos, {3, 5}, 4, movement_delay, 0);
		drawPixel(pos, {3, 6}, 1, movement_delay, 0);
		drawPixel(pos, {3, 7}, 1, movement_delay, 0);
		drawPixel(pos, {4, 2}, 1, movement_delay, 0);
		drawPixel(pos, {4, 3}, 5, movement_delay, 0);
		drawPixel(pos, {4, 4}, 5, movement_delay, 0);
		drawPixel(pos, {4, 5}, 5, movement_delay, 0);
		drawPixel(pos, {4, 6}, 1, movement_delay, 0);
		drawPixel(pos, {4, 7}, 1, movement_delay, 0);
		drawPixel(pos, {5, 1}, 4, movement_delay, 0);
		drawPixel(pos, {5, 3}, 1, movement_delay, 0);
		drawPixel(pos, {5, 4}, 1, movement_delay, 0);
		drawPixel(pos, {5, 5}, 1, movement_delay, 0);
		drawPixel(pos, {5, 6}, 1, movement_delay, 0);
		drawPixel(pos, {6, 0}, 4, movement_delay, 0);
		drawPixel(pos, {6, 4}, 1, movement_delay, 0);
		drawPixel(pos, {6, 5}, 1, movement_delay, 0);
		drawPixel(pos, {6, 7}, 1, movement_delay, 0);
		drawPixel(pos, {6, 8}, 1, movement_delay, 0);
		drawPixel(pos, {6, 9}, 1, movement_delay, 0);
		drawPixel(pos, {7, 0}, 4, movement_delay, 0);
		drawPixel(pos, {7, 1}, 1, movement_delay, 0);
		drawPixel(pos, {7, 4}, 1, movement_delay, 0);
		drawPixel(pos, {7, 5}, 1, movement_delay, 0);
		drawPixel(pos, {7, 6}, 1, movement_delay, 0);
		drawPixel(pos, {7, 7}, 1, movement_delay, 0);
		drawPixel(pos, {7, 8}, 1, movement_delay, 0);
		drawPixel(pos, {8, 2}, 1, movement_delay, 0);
		drawPixel(pos, {8, 3}, 1, movement_delay, 0);
		drawPixel(pos, {8, 5}, 1, movement_delay, 0);
		drawPixel(pos, {8, 6}, 1, movement_delay, 0);
		drawPixel(pos, {8, 7}, 1, movement_delay, 0);
		drawPixel(pos, {9, 4}, 1, movement_delay, 0);
		return;
	}

	int rotation = 0;
	if (direction == RIGHT)
	{
		movement_delay = -movement_delay;
		rotation = 1;
	}

	drawPixel(pos, {0, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {0, 8}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {1, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {2, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 3}, 4, 0, movement_delay, rotation);
	drawPixel(pos, {3, 4}, 5, 0, movement_delay, rotation);
	drawPixel(pos, {3, 5}, 4, 0, movement_delay, rotation);
	drawPixel(pos, {3, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {3, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 3}, 5, 0, movement_delay, rotation);
	drawPixel(pos, {4, 4}, 5, 0, movement_delay, rotation);
	drawPixel(pos, {4, 5}, 5, 0, movement_delay, rotation);
	drawPixel(pos, {4, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {4, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {5, 1}, 4, 0, movement_delay, rotation);
	drawPixel(pos, {5, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {5, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {5, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {5, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 0}, 4, 0, movement_delay, rotation);
	drawPixel(pos, {6, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 8}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {6, 9}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 0}, 4, 0, movement_delay, rotation);
	drawPixel(pos, {7, 1}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 4}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {7, 8}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 2}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 3}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 5}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 6}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {8, 7}, 1, 0, movement_delay, rotation);
	drawPixel(pos, {9, 4}, 1, 0, movement_delay, rotation);
}

void Painter::drawYouLose()
{
	int row, col;
	getmaxyx(stdscr, row, col);

	start_color();
	init_pair(6, COLOR_WHITE, COLOR_BLACK);

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		for (int j = (row / 2) - 10; j <= (row / 2) + 10; j++)
		{
			mvwaddch(stdscr, j, i, ' ' | COLOR_PAIR(6));
		}
	}

	for (int i = (row / 2) - 10; i <= (row / 2) + 10; i++)
	{
		mvwaddch(stdscr, i, (col / 2) - 30, '/' | COLOR_PAIR(6));
		mvwaddch(stdscr, i, (col / 2) + 30, '\\' | COLOR_PAIR(6));
	}

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		mvwaddch(stdscr, (row / 2) - 10, i, '=' | COLOR_PAIR(6));
		mvwaddch(stdscr, (row / 2) + 10, i, '=' | COLOR_PAIR(6));
	}
	mvwprintw(stdscr, (row / 2) - 5, (col / 2) - 4, "You lose");
	mvwprintw(stdscr, (row / 2) - 3, (col / 2) - 10, "Gameplay time = %ds", std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start));
}

void Painter::drawYouWin()
{
	int row, col;
	getmaxyx(stdscr, row, col);

	start_color();
	init_pair(6, COLOR_WHITE, COLOR_BLACK);

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		for (int j = (row / 2) - 10; j <= (row / 2) + 10; j++)
		{
			mvwaddch(stdscr, j, i, ' ' | COLOR_PAIR(6));
		}
	}

	for (int i = (row / 2) - 10; i <= (row / 2) + 10; i++)
	{
		mvwaddch(stdscr, i, (col / 2) - 30, '/' | COLOR_PAIR(6));
		mvwaddch(stdscr, i, (col / 2) + 30, '\\' | COLOR_PAIR(6));
	}

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		mvwaddch(stdscr, (row / 2) - 10, i, '=' | COLOR_PAIR(6));
		mvwaddch(stdscr, (row / 2) + 10, i, '=' | COLOR_PAIR(6));
	}
	mvwprintw(stdscr, (row / 2) - 5, (col / 2) - 3, "You win");
	mvwprintw(stdscr, (row / 2) - 3, (col / 2) - 10, "Gameplay time = %ds", std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start));
}

void Painter::drawInterface(int energy, int progress)
{
	if (progress == 100)
		drawYouWin();
	else if (progress == 0)
		drawYouLose();

	int row, col;
	getmaxyx(stdscr, row, col);

	start_color();
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);

	for (int i = 0; i < col; i++)
		for (int j = 1; j < 5; j++)
			mvwaddch(stdscr, row - j, i, ' ' | COLOR_PAIR(6));
	for (int i = 0; i < col; i++)
		mvwaddch(stdscr, row - 4, i, '=' | COLOR_PAIR(6));

	int max_px_av = col - 12;

	mvwprintw(stdscr, row - 3, 0, "Energy:   <");
	mvwprintw(stdscr, row - 3, col - 1, ">");
	mvwprintw(stdscr, row - 2, 0, "Progress: <");
	mvwprintw(stdscr, row - 2, col - 1, ">");

	for (int i = 0; i < max_px_av; i++)
	{
		mvwaddch(stdscr, row - 3, i + 11, (i * 100) / max_px_av < energy ? '\\' | COLOR_PAIR(8) : ' ' | COLOR_PAIR(6));
		mvwaddch(stdscr, row - 2, i + 11, (i * 100) / max_px_av < progress ? '/' | COLOR_PAIR(7) : ' ' | COLOR_PAIR(6));
	}
}

void Painter::drawField(Field *field)
{
	clear();

	int row, col;
	getmaxyx(stdscr, row, col);

	const Event *event;

	for (int i = 0; i < field->getWidth(); i++)
	{
		for (int j = 0; j < field->getHeight(); j++)
		{
			drawEmptyCell({i, j});
			event = field->getCell({i, j})->getEvent();
			if (dynamic_cast<const AddProgress *>(event))
			{
				drawAddProgress({i, j});
			}
			else if (dynamic_cast<const SpawnEnemy *>(event))
			{
				drawSpawnEnemy({i, j});
			}
			else if (dynamic_cast<const AddEnergy *>(event))
			{
				drawAddEnergy({i, j});
			}
			else if (dynamic_cast<const TeleportPlayer *>(event))
			{
				drawTeleportPlayer({i, j});
			}
		}
	}

	for (auto elem : *(field->getEnemysContainer()))
	{
		drawEnemy(elem.position, elem.entity->getDirection(), elem.entity->movementDelay());
	}

	EntityContainer player_container = *(field->getPlayerContainer());
	if (player_container.entity != nullptr)
	{
		drawPlayer(player_container.position, player_container.entity->getDirection(), player_container.entity->movementDelay());
		drawInterface(dynamic_cast<const Player *>(player_container.entity)->getEnergyRelation(), dynamic_cast<const Player *>(player_container.entity)->getProgressRelation());
	}

	mvwprintw(stdscr, row - 1, 0, "Average FPS: %d", ((std::chrono::seconds(1) * frame_no++) / (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start) + std::chrono::seconds(1))));
	refresh();
}
