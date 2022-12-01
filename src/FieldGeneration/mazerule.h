#ifndef MAZERULE_H
#define MAZERULE_H

#include "./../Field/field.h"
#include "./../Field/position.h"
#include "./../Field/cell.h"
#include "./../Entity/direction.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

template <int cell_percent>
class MazeRule
{
public:
    void apply(Field *field);

private:
    void openCell(int **maze, Position position, int &need_to_open, int max_x, int max_y);
};

template <int cell_percent>
void MazeRule<cell_percent>::apply(Field *field)
{
    int **maze = new int *[field->getHeight()];
    for (int i = 0; i < field->getHeight(); i++)
    {
        maze[i] = new int[field->getWidth()];
        for (int j = 0; j < field->getWidth(); j++)
        {
            maze[i][j] = 1;
        }
    }

    Position player_position = field->getPlayerContainer()->getPosition();
    if (player_position.getX() == -1 || player_position.getY() == -1)
        player_position = Position(0, 0);
    int need_to_open = cell_percent * field->getWidth() * field->getWidth() / 100;
    openCell(maze, player_position, need_to_open, field->getWidth(), field->getHeight());

    for (int i = 0; i < field->getHeight(); i++)
    {
        for (int j = 0; j < field->getWidth(); j++)
        {
            if (maze[i][j] && !field->getCell(Position(j, i))->isOccupied() && !field->getCell(Position(j, i))->getEvent())
                field->addWall(Position(j, i));
        }

        delete[] maze[i];
    }
    delete[] maze;
}

template <int cell_percent>
void MazeRule<cell_percent>::openCell(int **maze, Position position, int &need_to_open, int max_x, int max_y)
{
    if (!need_to_open || !maze[position.getY()][position.getX()])
        return;

    maze[position.getY()][position.getX()] = 0;
    need_to_open -= 1;

    std::vector<int> side_directions = {0, 1, 2, 3};
    std::random_shuffle(side_directions.begin(), side_directions.end());
    for (auto elem : side_directions)
    {
        openCell(maze, position.calculateSidePosition(elem, max_x, max_y), need_to_open, max_x, max_y);
        if (!need_to_open)
            break;
    }
}

#endif
