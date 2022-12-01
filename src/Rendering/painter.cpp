#include <wchar.h>
#include <curses.h>
#include <ncurses.h>
#include <wctype.h>
#include <locale.h>
#include "painter.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Entity/entitycontainer.h"
#include "./../Entity/enemy.h"
#include "./../Entity/Player/player.h"
#include "./../Event/addenergy.h"
#include "./../Event/addprogress.h"
#include "./../Event/spawnenemy.h"
#include "./../Event/teleportplayer.h"
#include "./../Entity/direction.h"

#define CELL_WIDTH 20
#define CELL_HEIGHT 10

Painter::Painter()
{
	_start = std::chrono::steady_clock::now();
	_frame_no = 1;
}

Painter::~Painter()
{
}

void Painter::drawEmptyCell(Position pos)
{
	for (int i = (CELL_HEIGHT + 1) * pos.getY(); i < (CELL_HEIGHT + 1) * (pos.getY() + 1) - 1; i++)
		for (int j = (CELL_WIDTH + 2) * pos.getX(); j < (CELL_WIDTH + 2) * (pos.getX() + 1) - 2; j++)
			mvwaddch(stdscr, i - _y_offset, j - _x_offset, '*' | A_DIM);
}

void Painter::drawAddProgress(Position pos)
{
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
	mvwaddch(stdscr, (CELL_HEIGHT + 1) * cell_pos.getY() + pixel_pos.getX() + h_movement_delay - _y_offset, (CELL_WIDTH + 2) * cell_pos.getX() + (CELL_WIDTH - 1) * rotation + (1 - rotation * 2) * (pixel_pos.getY() * 2) + v_movement_delay * 2 - _x_offset, ' ' | COLOR_PAIR(color_scheme));
	mvwaddch(stdscr, (CELL_HEIGHT + 1) * cell_pos.getY() + pixel_pos.getX() + h_movement_delay - _y_offset, (CELL_WIDTH + 2) * cell_pos.getX() + (CELL_WIDTH - 1) * rotation + (1 - rotation * 2) * (pixel_pos.getY() * 2 + 1) + v_movement_delay * 2 - _x_offset, ' ' | COLOR_PAIR(color_scheme));
}

void Painter::drawPlayer(Position pos, int direction, int movement_delay)
{
	if (direction == Direction::DOWN)
		movement_delay = -movement_delay;

	if (direction == Direction::DOWN || direction == Direction::UP)
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
	if (direction == Direction::RIGHT)
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
	if (direction == Direction::DOWN)
		movement_delay = -movement_delay;

	if (direction == Direction::DOWN || direction == Direction::UP)
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
	if (direction == Direction::RIGHT)
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

void Painter::drawWall(Position pos)
{
	drawPixel(pos, {0, 0}, 1, 0, 0);
	drawPixel(pos, {0, 1}, 1, 0, 0);
	drawPixel(pos, {0, 2}, 1, 0, 0);
	drawPixel(pos, {0, 3}, 1, 0, 0);
	drawPixel(pos, {0, 4}, 1, 0, 0);
	drawPixel(pos, {0, 5}, 1, 0, 0);
	drawPixel(pos, {0, 6}, 1, 0, 0);
	drawPixel(pos, {0, 7}, 1, 0, 0);
	drawPixel(pos, {0, 8}, 1, 0, 0);
	drawPixel(pos, {0, 9}, 1, 0, 0);
	drawPixel(pos, {1, 0}, 1, 0, 0);
	drawPixel(pos, {1, 1}, 5, 0, 0);
	drawPixel(pos, {1, 2}, 5, 0, 0);
	drawPixel(pos, {1, 3}, 5, 0, 0);
	drawPixel(pos, {1, 4}, 5, 0, 0);
	drawPixel(pos, {1, 5}, 5, 0, 0);
	drawPixel(pos, {1, 6}, 5, 0, 0);
	drawPixel(pos, {1, 7}, 5, 0, 0);
	drawPixel(pos, {1, 8}, 5, 0, 0);
	drawPixel(pos, {1, 9}, 1, 0, 0);
	drawPixel(pos, {2, 0}, 1, 0, 0);
	drawPixel(pos, {2, 1}, 5, 0, 0);
	drawPixel(pos, {2, 2}, 1, 0, 0);
	drawPixel(pos, {2, 3}, 1, 0, 0);
	drawPixel(pos, {2, 4}, 1, 0, 0);
	drawPixel(pos, {2, 5}, 5, 0, 0);
	drawPixel(pos, {2, 6}, 5, 0, 0);
	drawPixel(pos, {2, 7}, 1, 0, 0);
	drawPixel(pos, {2, 8}, 5, 0, 0);
	drawPixel(pos, {2, 9}, 1, 0, 0);
	drawPixel(pos, {3, 0}, 1, 0, 0);
	drawPixel(pos, {3, 1}, 5, 0, 0);
	drawPixel(pos, {3, 2}, 5, 0, 0);
	drawPixel(pos, {3, 3}, 5, 0, 0);
	drawPixel(pos, {3, 4}, 5, 0, 0);
	drawPixel(pos, {3, 5}, 5, 0, 0);
	drawPixel(pos, {3, 6}, 1, 0, 0);
	drawPixel(pos, {3, 7}, 1, 0, 0);
	drawPixel(pos, {3, 8}, 5, 0, 0);
	drawPixel(pos, {3, 9}, 1, 0, 0);
	drawPixel(pos, {4, 0}, 1, 0, 0);
	drawPixel(pos, {4, 1}, 5, 0, 0);
	drawPixel(pos, {4, 2}, 5, 0, 0);
	drawPixel(pos, {4, 3}, 5, 0, 0);
	drawPixel(pos, {4, 4}, 5, 0, 0);
	drawPixel(pos, {4, 5}, 5, 0, 0);
	drawPixel(pos, {4, 6}, 5, 0, 0);
	drawPixel(pos, {4, 7}, 5, 0, 0);
	drawPixel(pos, {4, 8}, 5, 0, 0);
	drawPixel(pos, {4, 9}, 1, 0, 0);
	drawPixel(pos, {5, 0}, 1, 0, 0);
	drawPixel(pos, {5, 1}, 5, 0, 0);
	drawPixel(pos, {5, 2}, 5, 0, 0);
	drawPixel(pos, {5, 3}, 1, 0, 0);
	drawPixel(pos, {5, 4}, 1, 0, 0);
	drawPixel(pos, {5, 5}, 5, 0, 0);
	drawPixel(pos, {5, 6}, 5, 0, 0);
	drawPixel(pos, {5, 7}, 1, 0, 0);
	drawPixel(pos, {5, 8}, 5, 0, 0);
	drawPixel(pos, {5, 9}, 1, 0, 0);
	drawPixel(pos, {6, 0}, 1, 0, 0);
	drawPixel(pos, {6, 1}, 5, 0, 0);
	drawPixel(pos, {6, 2}, 5, 0, 0);
	drawPixel(pos, {6, 3}, 5, 0, 0);
	drawPixel(pos, {6, 4}, 5, 0, 0);
	drawPixel(pos, {6, 5}, 5, 0, 0);
	drawPixel(pos, {6, 6}, 5, 0, 0);
	drawPixel(pos, {6, 7}, 5, 0, 0);
	drawPixel(pos, {6, 8}, 5, 0, 0);
	drawPixel(pos, {6, 9}, 1, 0, 0);
	drawPixel(pos, {7, 0}, 1, 0, 0);
	drawPixel(pos, {7, 1}, 5, 0, 0);
	drawPixel(pos, {7, 2}, 1, 0, 0);
	drawPixel(pos, {7, 3}, 5, 0, 0);
	drawPixel(pos, {7, 4}, 5, 0, 0);
	drawPixel(pos, {7, 5}, 1, 0, 0);
	drawPixel(pos, {7, 6}, 1, 0, 0);
	drawPixel(pos, {7, 7}, 1, 0, 0);
	drawPixel(pos, {7, 8}, 5, 0, 0);
	drawPixel(pos, {7, 9}, 1, 0, 0);
	drawPixel(pos, {8, 0}, 1, 0, 0);
	drawPixel(pos, {8, 1}, 5, 0, 0);
	drawPixel(pos, {8, 2}, 5, 0, 0);
	drawPixel(pos, {8, 3}, 5, 0, 0);
	drawPixel(pos, {8, 4}, 5, 0, 0);
	drawPixel(pos, {8, 5}, 5, 0, 0);
	drawPixel(pos, {8, 6}, 5, 0, 0);
	drawPixel(pos, {8, 7}, 5, 0, 0);
	drawPixel(pos, {8, 8}, 5, 0, 0);
	drawPixel(pos, {8, 9}, 1, 0, 0);
	drawPixel(pos, {9, 0}, 1, 0, 0);
	drawPixel(pos, {9, 1}, 1, 0, 0);
	drawPixel(pos, {9, 2}, 1, 0, 0);
	drawPixel(pos, {9, 3}, 1, 0, 0);
	drawPixel(pos, {9, 4}, 1, 0, 0);
	drawPixel(pos, {9, 5}, 1, 0, 0);
	drawPixel(pos, {9, 6}, 1, 0, 0);
	drawPixel(pos, {9, 7}, 1, 0, 0);
	drawPixel(pos, {9, 8}, 1, 0, 0);
	drawPixel(pos, {9, 9}, 1, 0, 0);
}

void Painter::drawYouLose()
{
	int row, col;
	getmaxyx(stdscr, row, col);

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		for (int j = (row / 2) - 10; j <= (row / 2) + 10; j++)
		{
			mvwaddch(stdscr, j, i, ' ' | COLOR_PAIR(6));
		}
	}

	for (int i = (row / 2) - 10; i <= (row / 2) + 10; i++)
	{
		mvwaddch(stdscr, i, (col / 2) - 30, ACS_VLINE | COLOR_PAIR(6));
		mvwaddch(stdscr, i, (col / 2) + 30, ACS_VLINE | COLOR_PAIR(6));
	}

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		mvwaddch(stdscr, (row / 2) - 10, i, ACS_HLINE | COLOR_PAIR(6));
		mvwaddch(stdscr, (row / 2) + 10, i, ACS_HLINE | COLOR_PAIR(6));
	}

	mvwaddch(stdscr, (row / 2) - 10, (col / 2) - 30, ACS_ULCORNER | COLOR_PAIR(6));
	mvwaddch(stdscr, (row / 2) + 10, (col / 2) - 30, ACS_LLCORNER | COLOR_PAIR(6));
	mvwaddch(stdscr, (row / 2) + 10, (col / 2) + 30, ACS_LRCORNER | COLOR_PAIR(6));
	mvwaddch(stdscr, (row / 2) - 10, (col / 2) + 30, ACS_URCORNER | COLOR_PAIR(6));

	mvwprintw(stdscr, (row / 2) - 5, (col / 2) - 4, "You lose");
	mvwprintw(stdscr, (row / 2) - 3, (col / 2) - 10, "Gameplay time = %ds", std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - _start));
}

void Painter::drawYouWin()
{
	int row, col;
	getmaxyx(stdscr, row, col);

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		for (int j = (row / 2) - 10; j <= (row / 2) + 10; j++)
		{
			mvwaddch(stdscr, j, i, ' ' | COLOR_PAIR(6));
		}
	}

	for (int i = (row / 2) - 10; i <= (row / 2) + 10; i++)
	{
		mvwaddch(stdscr, i, (col / 2) - 30, ACS_VLINE | COLOR_PAIR(6));
		mvwaddch(stdscr, i, (col / 2) + 30, ACS_VLINE | COLOR_PAIR(6));
	}

	for (int i = (col / 2) - 30; i <= (col / 2) + 30; i++)
	{
		mvwaddch(stdscr, (row / 2) - 10, i, ACS_HLINE | COLOR_PAIR(6));
		mvwaddch(stdscr, (row / 2) + 10, i, ACS_HLINE | COLOR_PAIR(6));
	}

	mvwaddch(stdscr, (row / 2) - 10, (col / 2) - 30, ACS_ULCORNER | COLOR_PAIR(6));
	mvwaddch(stdscr, (row / 2) + 10, (col / 2) - 30, ACS_LLCORNER | COLOR_PAIR(6));
	mvwaddch(stdscr, (row / 2) + 10, (col / 2) + 30, ACS_LRCORNER | COLOR_PAIR(6));
	mvwaddch(stdscr, (row / 2) - 10, (col / 2) + 30, ACS_URCORNER | COLOR_PAIR(6));

	mvwprintw(stdscr, (row / 2) - 5, (col / 2) - 3, "You win");
	mvwprintw(stdscr, (row / 2) - 3, (col / 2) - 10, "Gameplay time = %ds", std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - _start));
}

void Painter::drawInterface(int energy, int progress)
{
	int row, col;
	getmaxyx(stdscr, row, col);

	for (int i = 0; i < col; i++)
		for (int j = 1; j < 5; j++)
			mvwaddch(stdscr, row - j, i, ' ' | COLOR_PAIR(6));
	for (int i = 0; i < col; i++)
		mvwaddch(stdscr, row - 4, i, ACS_S9 | COLOR_PAIR(6));

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

void Painter::drawField(const Field *field)
{
	clear();

	int row, col;
	getmaxyx(stdscr, row, col);

	int x_delay, y_delay;
	switch (field->getPlayerContainer()->getEntity()->getDirection())
	{
	case Direction::LEFT:
		x_delay = 1;
		y_delay = 0;
		break;
	case Direction::RIGHT:
		x_delay = -1;
		y_delay = 0;
		break;
	case Direction::UP:
		x_delay = 0;
		y_delay = 1;
		break;
	case Direction::DOWN:
		x_delay = 0;
		y_delay = -1;
		break;
	}

	_x_offset = (field->getPlayerContainer()->getPosition().getX() + 1) * 22 - col / 2 + field->getPlayerContainer()->getEntity()->movementDelay() * x_delay * 2;
	_y_offset = (field->getPlayerContainer()->getPosition().getY() + 1) * 11 - row / 2 + field->getPlayerContainer()->getEntity()->movementDelay() * y_delay;

	const Event *event;

	for (int i = 0; i < field->getWidth(); i++)
	{
		for (int j = 0; j < field->getHeight(); j++)
		{
			drawEmptyCell({i, j});
			event = field->getCell({i, j}).getEvent();
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

	for (auto elem : field->getEnemysContainer())
	{
		drawEnemy(elem.getPosition(), elem.getEntity()->getDirection(), elem.getEntity()->movementDelay());
	}

	for (auto elem : field->getWallsPositions())
	{
		drawWall(elem);
	}

	EntityContainer player_container = *(field->getPlayerContainer());
	if (player_container.getEntity() != nullptr)
	{
		drawPlayer(player_container.getPosition(), player_container.getEntity()->getDirection(), player_container.getEntity()->movementDelay());
		drawInterface(dynamic_cast<const Player *>(player_container.getEntity())->getEnergyRelation(), dynamic_cast<const Player *>(player_container.getEntity())->getProgressRelation());
	}

	if (field->getGameStatus() > 0)
		drawYouWin();
	if (field->getGameStatus() < 0)
		drawYouLose();

	mvwprintw(stdscr, row - 1, 0, "Average FPS: %d", ((std::chrono::seconds(1) * _frame_no++) / (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - _start) + std::chrono::seconds(1))));
	refresh();
}
