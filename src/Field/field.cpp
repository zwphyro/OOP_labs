#include "field.h"
#include "cell.h"
#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"
#include "./../Event/eventfacade.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

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

	_player_container.setEntity(nullptr);
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
		delete elem.getEntity();

	if (_event_facade)
		delete _event_facade;
}

void Field::setEventFacade(EventFacade *event_facade)
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field facade set"));
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
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "field random position rejected"));
		return {-1, -1};
	}

	notify(LogMessage(LogLevels::GAME_ENTITIES, "field random position sent"));
	return free_positions.at(std::rand() % free_positions.size());
}

int Field::getWidth() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field width sent"));
	return _width;
}

int Field::getHeight() const
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field height sent"));
	return _height;
}

EntityContainer *Field::getPlayerContainer()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field player container sent"));
	return &_player_container;
}

const EntityContainer *Field::getPlayerContainer() const
{
	return &_player_container;
}

EnemyVector *Field::getEnemysContainer()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field enemy container sent"));
	return &_enemys_container;
}

const EnemyVector Field::getEnemysContainer() const
{
	return _enemys_container;
}

void Field::addEntity(Player *entity, Position position)
{
	if (position.getX() >= _width || position.getX() < 0 || position.getY() >= _height || position.getY() < 0 || _cell_arr[position.getY()][position.getX()]->isOccupied())
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "field player adding rejected"));
		return;
	}

	_player_container.setEntity(entity);
	_player_container.setPosition(position);
	_cell_arr[position.getY()][position.getX()]->playerStepped();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field player added"));
}

void Field::addEntity(Enemy *entity, Position position)
{
	if (position.getX() >= _width || position.getX() < 0 || position.getY() >= _height || position.getY() < 0 || _cell_arr[position.getY()][position.getX()]->isOccupied())
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "field enemy adding rejected"));
		return;
	}

	_enemys_container.push_back({entity, position});
	_cell_arr[position.getY()][position.getX()]->enemyStepped();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field enemy added"));
}

Cell *Field::getCell(Position position)
{
	if (position.getX() < 0 || position.getX() >= _width || position.getX() < 0 || position.getY() >= _height)
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "field cell access rejected"));
		return nullptr;
	}
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field cell sent"));
	return _cell_arr[position.getY()][position.getX()];
}

Cell Field::getCell(Position position) const
{
	if (position.getX() < 0 || position.getX() >= _width || position.getX() < 0 || position.getY() >= _height)
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "field cell access rejected"));
		return nullptr;
	}
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field cell sent"));
	return Cell(*_cell_arr[position.getY()][position.getX()]);
}

EventFacade &Field::getEventFacade()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "field facade sent"));
	return *_event_facade;
}
