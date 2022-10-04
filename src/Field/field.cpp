#include "field.h"

Field::Field(int width, int height) : width(width), height(height), factory(nullptr)
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

	factory = new EventFactory(*obj.factory);

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
		factory = new EventFactory(*obj.factory);

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
	factory = nullptr;
	std::swap(factory, obj.factory);
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
		factory = nullptr;
		std::swap(factory, obj.factory);
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

	if (factory)
		delete factory;
}

void Field::setFactory(EventFactory *factory)
{
	this->factory = factory;
}

Position Field::getRandomFreePosition()
{
	std::srand(std::time(nullptr));

	Position random_position;
	do
	{
		random_position.x = std::rand() % width;
		random_position.y = std::rand() % height;
	} while (cell_arr[random_position.y][random_position.x]->isOccupied());

	return random_position;
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

void Field::addEntity(const Player *entity, Position position)
{
	if (position.x >= width || position.x < 0 || position.y >= height || position.y < 0 || cell_arr[position.y][position.x]->isOccupied())
		return;

	player_container.entity = entity;
	player_container.position = position;
	cell_arr[position.y][position.x]->playerStepped();
}

void Field::addEntity(const Enemy *entity, Position position)
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

EventFactory &Field::getFactory()
{
	return *factory;
}
