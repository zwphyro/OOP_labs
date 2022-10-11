#include "field.h"
#include "cell.h"
#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"
#include "./../Event/eventfacade.h"

Field::Field(int width, int height) : _width(width), _height(height), _event_facade(nullptr)
{
	_cell_arr = new Cell **[height];

	for (int i = 0; i < height; i++)
	{
		_cell_arr[i] = new Cell *[width];
		for (int j = 0; j < width; j++)
		{
			_cell_arr[i][j] = new Cell;
		}
	}

	_player_container.entity = nullptr;
}

Field::Field(const Field &obj) : _width(obj._width), _height(obj._height), _player_container(obj._player_container)
{
	_cell_arr = new Cell **[_height];
	for (int i = 0; i < _height; i++)
	{
		_cell_arr[i] = new Cell *[_width];
		for (int j = 0; j < _width; j++)
		{
			_cell_arr[i][j] = new Cell(*obj._cell_arr[i][j]);
		}
	}

	_event_facade = new EventFacade(*obj._event_facade);

	for (auto elem : obj._enemys_container)
		_enemys_container.push_back(elem);
}

Field &Field::operator=(const Field &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < _height; i++)
		{
			for (int j = 0; j < _width; j++)
			{
				delete _cell_arr[i][j];
			}
			delete[] _cell_arr[i];
		}
		delete[] _cell_arr;

		_enemys_container.clear();

		_width = obj._width;
		_height = obj._height;
		_player_container = obj._player_container;
		_event_facade = new EventFacade(*obj._event_facade);

		_cell_arr = new Cell **[_height];
		for (int i = 0; i < _height; i++)
		{
			_cell_arr[i] = new Cell *[_width];
			for (int j = 0; j < _width; j++)
			{
				_cell_arr[i][j] = new Cell(*obj._cell_arr[i][j]);
			}
		}

		for (auto elem : obj._enemys_container)
			_enemys_container.push_back(elem);
	}

	return *this;
}

Field::Field(Field &&obj)
{
	std::swap(_width, obj._width);
	std::swap(_height, obj._height);
	_event_facade = nullptr;
	std::swap(_event_facade, obj._event_facade);
	_cell_arr = nullptr;
	std::swap(_cell_arr, obj._cell_arr);
	std::swap(_player_container, obj._player_container);
	_enemys_container.swap(obj._enemys_container);
}

Field &Field::operator=(Field &&obj)
{
	if (this != &obj)
	{
		std::swap(_width, obj._width);
		std::swap(_height, obj._height);
		_event_facade = nullptr;
		std::swap(_event_facade, obj._event_facade);
		_cell_arr = nullptr;
		std::swap(_cell_arr, obj._cell_arr);
		std::swap(_player_container, obj._player_container);
		_enemys_container.swap(obj._enemys_container);
	}

	return *this;
}

Field::~Field()
{
	if (_cell_arr)
	{
		for (int i = 0; i < _height; i++)
		{
			for (int j = 0; j < _width; j++)
			{
				delete _cell_arr[i][j];
			}
			delete[] _cell_arr[i];
		}
		delete[] _cell_arr;
	}

	for (auto elem : _enemys_container)
		delete elem.entity;

	if (_event_facade)
		delete _event_facade;
}

void Field::setEventFacade(EventFacade *event_facade)
{
	_event_facade = event_facade;
}

Position Field::getRandomFreePosition()
{
	std::srand(std::time(nullptr));

	std::vector<Position> free_positions;

	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _height; j++)
		{
			if (!(_cell_arr[j][i]->isOccupied() || _cell_arr[j][i]->getEvent()))
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
	return _width;
}

int Field::getHeight() const
{
	return _height;
}

EntityContainer *Field::getPlayerContainer()
{
	return &_player_container;
}

EnemyVector *Field::getEnemysContainer()
{
	return &_enemys_container;
}

void Field::addEntity(Player *entity, Position position)
{
	if (position.x >= _width || position.x < 0 || position.y >= _height || position.y < 0 || _cell_arr[position.y][position.x]->isOccupied())
		return;

	_player_container.entity = entity;
	_player_container.position = position;
	_cell_arr[position.y][position.x]->playerStepped();
}

void Field::addEntity(Enemy *entity, Position position)
{
	if (position.x >= _width || position.x < 0 || position.y >= _height || position.y < 0 || _cell_arr[position.y][position.x]->isOccupied())
		return;

	_enemys_container.push_back({entity, position});
	_cell_arr[position.y][position.x]->enemyStepped();
}

Cell *Field::getCell(Position position)
{
	return _cell_arr[position.y][position.x];
}

EventFacade &Field::getEventFacade()
{
	return *_event_facade;
}
