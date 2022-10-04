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
	int row, col;
	getmaxyx(stdscr, row, col);

	for (int i = (CELL_HEIGHT + 1) * pos.y; i < (CELL_HEIGHT + 1) * (pos.y + 1) - 1; i++)
		for (int j = (CELL_WIDTH + 2) * pos.x; j < (CELL_WIDTH + 2) * (pos.x + 1) - 2; j++)
			mvwaddch(stdscr, i, j, '*' | A_DIM);
	move(row - 1, col - 1);
}

void Painter::drawAddProgress(Position pos)
{
	int row, col;
	getmaxyx(stdscr, row, col);

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

	move(row - 1, col - 1);
}

void Painter::drawAddEnergy(Position pos)
{
	int row, col;
	getmaxyx(stdscr, row, col);

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

	move(row - 1, col - 1);
}

void Painter::drawSpawnEnemy(Position pos)
{
	int row, col;
	getmaxyx(stdscr, row, col);

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

	move(row - 1, col - 1);
}

void Painter::drawPixel(Position cell_pos, Position pixel_pos, int color_scheme, int h_movement_delay, int v_movement_delay, int rotation)
{
	mvwaddch(stdscr, (CELL_HEIGHT + 1) * cell_pos.y + pixel_pos.x + h_movement_delay, (CELL_WIDTH + 2) * cell_pos.x + (CELL_WIDTH - 1) * rotation + (1 - rotation * 2) * (pixel_pos.y * 2) + v_movement_delay * 2, ' ' | COLOR_PAIR(color_scheme));
	mvwaddch(stdscr, (CELL_HEIGHT + 1) * cell_pos.y + pixel_pos.x + h_movement_delay, (CELL_WIDTH + 2) * cell_pos.x + (CELL_WIDTH - 1) * rotation + (1 - rotation * 2) * (pixel_pos.y * 2 + 1) + v_movement_delay * 2, ' ' | COLOR_PAIR(color_scheme));
	refresh();
}

void Painter::drawPlayer(Position pos, int direction, int movement_delay)
{
	int row, col;
	getmaxyx(stdscr, row, col);
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

		move(row - 1, col - 1);
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

	move(row - 1, col - 1);
}

void Painter::drawEnemy(Position pos, int direction, int movement_delay)
{
	int row, col;
	getmaxyx(stdscr, row, col);
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);

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

	move(row - 1, col - 1);
}

void Painter::drawYouLose()
{
	int row, col;
	getmaxyx(stdscr, row, col);
	start_color();
	init_pair(10, COLOR_RED, COLOR_WHITE);

	for (int i = 0; i < col / 30 + 1; i++)
	{
		mvwaddch(stdscr, row - 3, 1 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 1 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 2 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 2 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 3 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 3 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 5 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 5 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 5 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 6 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 6 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 7 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 7 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 7 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 9 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 9 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 9 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 10 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 11 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 11 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 11 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 15 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 15 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 15 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 16 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 18 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 18 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 18 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 19 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 19 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 20 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 20 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 20 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 22 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 23 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 23 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 23 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 24 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 26 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 26 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 26 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 3, 27 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 2, 27 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
		mvwaddch(stdscr, row - 1, 27 + i * 30, '#' | A_BLINK | COLOR_PAIR(10));
	}
}

void Painter::drawYouWin()
{
	int row, col;
	getmaxyx(stdscr, row, col);
	start_color();
	init_pair(9, COLOR_GREEN, COLOR_WHITE);
	for (int i = 0; i < col / 30 + 1; i++)
	{
		mvwaddch(stdscr, row - 3, 1 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 1 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 2 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 2 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 3 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 3 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 5 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 5 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 5 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 6 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 6 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 7 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 7 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 7 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 9 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 9 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 9 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 10 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 11 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 11 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 11 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 15 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 15 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 16 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 16 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 17 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 17 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 18 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 18 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 19 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 19 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 21 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 21 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 22 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 22 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 22 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 23 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 23 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 25 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 25 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 25 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 26 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 3, 27 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 2, 27 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
		mvwaddch(stdscr, row - 1, 27 + i * 30, '#' | A_BLINK | COLOR_PAIR(9));
	}
}

void Painter::drawInterface(int energy, int progress)
{
	if (progress == 100)
	{
		drawYouWin();
		return;
	}
	else if (progress == 0)
	{
		drawYouLose();
		return;
	}

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

	// mvwprintw(stdscr, row - 1, 0, "Average FPS: %d", ((std::chrono::seconds(1) * frame_no++) / (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start) + std::chrono::seconds(1))));
}
