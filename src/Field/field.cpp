#include "field.h"
#include "cell.h"
#include "./../Entity/Player/player.h"
#include "./../Entity/enemy.h"
#include "./../Event/addenergy.h"
#include "./../Event/addprogress.h"
#include "./../Event/spawnenemy.h"
#include "./../Event/teleportplayer.h"
#include "./../Event/eventfacade.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"
#include "./../Interface/Options/optionsparameters.h"

Field::Field(const OptionsParameters *options)
{
	_width = options->getFieldWidth();
	_height = options->getFieldHeight();

	Player *player = new Player;
	_player_container.setEntity(player);
	_player_container.setPosition(Position(0, 0));

	_event_facade = new EventFacade(this, player);

	_cell_arr = new Cell **[_height];

	for (int i = 0; i < _height; i++)
	{
		_cell_arr[i] = new Cell *[_width];
		for (int j = 0; j < _width; j++)
		{
			_cell_arr[i][j] = new Cell;
		}
	}
	_cell_arr[0][0]->playerStepped();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: field was created;"));
}

Field::Field(const Field &obj)
{
	_width = obj._width;
	_height = obj._height;

	Player *player = new Player;
	_player_container.setEntity(player);
	_player_container.setPosition(obj._player_container.getPosition());

	_event_facade = new EventFacade(this, player);

	_cell_arr = new Cell **[_height];
	for (int i = 0; i < _height; i++)
	{
		_cell_arr[i] = new Cell *[_width];
		for (int j = 0; j < _width; j++)
		{
			_cell_arr[i][j] = new Cell;
			if (obj._cell_arr[i][j]->getEvent() == nullptr)
				continue;
			else if (dynamic_cast<const AddProgress *>(obj._cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddProgress));
			}
			else if (dynamic_cast<const AddEnergy *>(obj._cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddEnergy));
			}
			else if (dynamic_cast<const SpawnEnemy *>(obj._cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new SpawnEnemy));
			}
			else if (dynamic_cast<const TeleportPlayer *>(obj._cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new TeleportPlayer));
			}
		}
	}

	for (auto elem : obj._enemys_container)
	{
		_enemys_container.push_back(elem);
	}
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: field was created;"));
}

Field &Field::operator=(const Field &obj)
{
	if (this != &obj)
	{
		_width = obj._width;
		_height = obj._height;

		Player *player = new Player;
		_player_container.setEntity(player);
		_player_container.setPosition(obj._player_container.getPosition());

		_event_facade = new EventFacade(this, player);

		_cell_arr = new Cell **[_height];
		for (int i = 0; i < _height; i++)
		{
			_cell_arr[i] = new Cell *[_width];
			for (int j = 0; j < _width; j++)
			{
				_cell_arr[i][j] = new Cell;
				if (obj._cell_arr[i][j]->getEvent() == nullptr)
					continue;
				else if (dynamic_cast<const AddProgress *>(obj._cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddProgress));
				}
				else if (dynamic_cast<const AddEnergy *>(obj._cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddEnergy));
				}
				else if (dynamic_cast<const SpawnEnemy *>(obj._cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new SpawnEnemy));
				}
				else if (dynamic_cast<const TeleportPlayer *>(obj._cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new TeleportPlayer));
				}
			}
		}

		for (auto elem : obj._enemys_container)
		{
			_enemys_container.push_back(elem);
		}
	}

	return *this;
}

Field::Field(Field &&obj)
{
	std::swap(_width, obj._width);
	std::swap(_height, obj._height);

	Player *player = new Player;
	_player_container.setEntity(player);
	_player_container.setPosition(obj._player_container.getPosition());

	_event_facade = new EventFacade(this, player);
	std::swap(_cell_arr, obj._cell_arr);

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			if (_cell_arr[i][j]->getEvent() == nullptr)
				continue;
			else if (dynamic_cast<const AddProgress *>(_cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddProgress));
			}
			else if (dynamic_cast<const AddEnergy *>(_cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddEnergy));
			}
			else if (dynamic_cast<const SpawnEnemy *>(_cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new SpawnEnemy));
			}
			else if (dynamic_cast<const TeleportPlayer *>(_cell_arr[i][j]->getEvent()))
			{
				_cell_arr[i][j]->setEvent(_event_facade->getEvent(new TeleportPlayer));
			}
		}
	}

	_enemys_container.swap(obj._enemys_container);
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: field was created;"));
}

Field &Field::operator=(Field &&obj)
{
	if (this != &obj)
	{
		std::swap(_width, obj._width);
		std::swap(_height, obj._height);

		Player *player = new Player;
		_player_container.setEntity(player);
		_player_container.setPosition(obj._player_container.getPosition());

		_event_facade = new EventFacade(this, player);
		std::swap(_cell_arr, obj._cell_arr);

		for (int i = 0; i < _height; i++)
		{
			for (int j = 0; j < _width; j++)
			{
				if (_cell_arr[i][j]->getEvent() == nullptr)
					continue;
				else if (dynamic_cast<const AddProgress *>(_cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddProgress));
				}
				else if (dynamic_cast<const AddEnergy *>(_cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new AddEnergy));
				}
				else if (dynamic_cast<const SpawnEnemy *>(_cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new SpawnEnemy));
				}
				else if (dynamic_cast<const TeleportPlayer *>(_cell_arr[i][j]->getEvent()))
				{
					_cell_arr[i][j]->setEvent(_event_facade->getEvent(new TeleportPlayer));
				}
			}
		}

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

	delete _player_container.getEntity();
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
		notify(LogMessage(LogLevels::EXCEPTIONS, "Object: field; Event: failed to find random position;"));
		return {-1, -1};
	}

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
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: player container was sent with with the possibility of modifying;"));
	return &_player_container;
}

const EntityContainer *Field::getPlayerContainer() const
{
	return &_player_container;
}

EnemyVector *Field::getEnemysContainer()
{
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: enemy container was sent with with the possibility of modifying;"));
	return &_enemys_container;
}

const EnemyVector Field::getEnemysContainer() const
{
	return _enemys_container;
}

void Field::addEntity(Enemy *entity, Position position)
{
	if (position.getX() >= _width || position.getX() < 0 || position.getY() >= _height || position.getY() < 0 || _cell_arr[position.getY()][position.getX()]->isOccupied())
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "Object: field; Event: attempt to add an enemy outside the field;"));
		return;
	}

	entity->makeObservable(*this);
	_enemys_container.push_back({entity, position});
	_cell_arr[position.getY()][position.getX()]->enemyStepped();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: new enemy has been added to the field;"));
}

Cell *Field::getCell(Position position)
{
	if (position.getX() < 0 || position.getX() >= _width || position.getX() < 0 || position.getY() >= _height)
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "Object: field; Event: attempt to access an cell outside the field;"));
		return nullptr;
	}
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: field; Event: cell was sent with with the possibility of modifying;"));
	return _cell_arr[position.getY()][position.getX()];
}

Cell Field::getCell(Position position) const
{
	if (position.getX() < 0 || position.getX() >= _width || position.getX() < 0 || position.getY() >= _height)
	{
		notify(LogMessage(LogLevels::EXCEPTIONS, "Object: field; Event: attempt to access an cell outside the field;"));
		return nullptr;
	}
	return Cell(*_cell_arr[position.getY()][position.getX()]);
}

EventFacade *Field::getEventFacade()
{
	return _event_facade;
}
