#include "field.h"

Field::Field(int width, int height) : width(width), height(height), event_facade(nullptr)
{
	cell_arr = new Cell **[height];

	for (int i = 0; i < height; i++)
	{
		cell_arr[i] = new Cell *[width];
		for (int j = 0; j < width; j++)
		{
			cell_arr[i][j] = new Cell;
		}
	}

	player_container.entity = nullptr;
}

Field::Field(const Field &obj) : width(obj.width), height(obj.height), player_container(obj.player_container)
{
	cell_arr = new Cell **[height];
	for (int i = 0; i < height; i++)
	{
		cell_arr[i] = new Cell *[width];
		for (int j = 0; j < width; j++)
		{
			cell_arr[i][j] = new Cell(*obj.cell_arr[i][j]);
		}
	}

	event_facade = new EventFacade(*obj.event_facade);

	for (auto elem : obj.enemys_container)
		enemys_container.push_back(elem);
}

Field &Field::operator=(const Field &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				delete cell_arr[i][j];
			}
			delete[] cell_arr[i];
		}
		delete[] cell_arr;

		enemys_container.clear();

		width = obj.width;
		height = obj.height;
		player_container = obj.player_container;
		event_facade = new EventFacade(*obj.event_facade);

		cell_arr = new Cell **[height];
		for (int i = 0; i < height; i++)
		{
			cell_arr[i] = new Cell *[width];
			for (int j = 0; j < width; j++)
			{
				cell_arr[i][j] = new Cell(*obj.cell_arr[i][j]);
			}
		}

		for (auto elem : obj.enemys_container)
			enemys_container.push_back(elem);
	}

	return *this;
}

Field::Field(Field &&obj)
{
	std::swap(width, obj.width);
	std::swap(height, obj.height);
	event_facade = nullptr;
	std::swap(event_facade, obj.event_facade);
	cell_arr = nullptr;
	std::swap(cell_arr, obj.cell_arr);
	std::swap(player_container, obj.player_container);
	enemys_container.swap(obj.enemys_container);
}

Field &Field::operator=(Field &&obj)
{
	if (this != &obj)
	{
		std::swap(width, obj.width);
		std::swap(height, obj.height);
		event_facade = nullptr;
		std::swap(event_facade, obj.event_facade);
		cell_arr = nullptr;
		std::swap(cell_arr, obj.cell_arr);
		std::swap(player_container, obj.player_container);
		enemys_container.swap(obj.enemys_container);
	}

	return *this;
}

Field::~Field()
{
	if (cell_arr)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				delete cell_arr[i][j];
			}
			delete[] cell_arr[i];
		}
		delete[] cell_arr;
	}

	for (auto elem : enemys_container)
		delete elem.entity;

	if (event_facade)
		delete event_facade;
}

void Field::setEventFacade(EventFacade *event_facade)
{
	this->event_facade = event_facade;
}

Position Field::getRandomFreePosition()
{
	std::srand(std::time(nullptr));

	std::vector<Position> free_positions;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (!(cell_arr[j][i]->isOccupied() || cell_arr[j][i]->getEvent()))
			{
				free_positions.push_back(Position(i, j));
			}
		}
	}
	if (free_positions.size() == 0)
		return {0, 0};

	return free_positions.at(std::rand() % free_positions.size());
}

int Field::getWidth() const
{
	return width;
}

int Field::getHeight() const
{
	return height;
}

EntityContainer *Field::getPlayerContainer()
{
	return &player_container;
}

EnemyVector *Field::getEnemysContainer()
{
	return &enemys_container;
}

void Field::addEntity(Player *entity, Position position)
{
	if (position.x >= width || position.x < 0 || position.y >= height || position.y < 0 || cell_arr[position.y][position.x]->isOccupied())
		return;

	player_container.entity = entity;
	player_container.position = position;
	cell_arr[position.y][position.x]->playerStepped();
}

void Field::addEntity(Enemy *entity, Position position)
{
	if (position.x >= width || position.x < 0 || position.y >= height || position.y < 0 || cell_arr[position.y][position.x]->isOccupied())
		return;

	enemys_container.push_back({entity, position});
	cell_arr[position.y][position.x]->enemyStepped();
}

Cell *Field::getCell(Position position)
{
	return cell_arr[position.y][position.x];
}

EventFacade &Field::getEventFacade()
{
	return *event_facade;
}
