#include "interactor.h"
#include "player.h"
#include "./../direction.h"
#include "./../../Field/cell.h"
#include "./../../Field/field.h"
#include "./../../Field/position.h"
#include "./../../Event/addprogress.h"
#include "./../../Event/spawnenemy.h"
#include "./../../Event/eventfacade.h"
#include "./../../Reading/commands.h"

Interactor::Interactor(Field *field, Player *player) : _field(field), _player(player)
{
}

Interactor::~Interactor()
{
	if (_player)
		delete _player;
}

void Interactor::setPlayer(Player *player)
{
	_player = player;
}

void Interactor::setField(Field *field)
{
	_field = field;
}

void Interactor::updatePlayer(int command)
{
	if (_player->getProgressRelation() == 100 || _player->getProgressRelation() == 0)
		return;

	_player->changeEnergy();
	_player->changeProgress();
	_player->changeSpeed();

	switch (command)
	{
	case Commands::MOVE_UP:
	case Commands::MOVE_DOWN:
	case Commands::MOVE_LEFT:
	case Commands::MOVE_RIGHT:
		movePlayer(command);
		break;
	case Commands::SHOOT:
		shoot();
		break;
	default:
		break;
	}
}

Position Interactor::calculateSidePosition(Position position, int direction)
{
	int old_x = position.x;
	int old_y = position.y;
	int new_x, new_y;

	switch (direction)
	{
	case Direction::UP:
		new_x = old_x;
		new_y = (old_y - 1 + _field->getHeight()) % _field->getHeight();
		break;
	case Direction::DOWN:
		new_x = old_x;
		new_y = (old_y + 1) % _field->getHeight();
		break;
	case Direction::RIGHT:
		new_x = (old_x + 1) % _field->getWidth();
		new_y = old_y;
		break;
	case Direction::LEFT:
		new_x = (old_x - 1 + _field->getWidth()) % _field->getWidth();
		new_y = old_y;
		break;
	}

	return {new_x, new_y};
}

void Interactor::movePlayer(int direction)
{
	if (_player == nullptr || _field == nullptr)
		return;

	if (!_player->moveStart(direction))
		return;

	EntityContainer *player_container = _field->getPlayerContainer();
	Position new_position = calculateSidePosition(player_container->position, direction);

	Cell *new_player_cell = _field->getCell(new_position);
	Cell *old_player_cell = _field->getCell(player_container->position);
	if (new_player_cell->isOccupied())
		return;

	player_container->position = new_position;
	old_player_cell->entityGone();
	new_player_cell->playerStepped();
	_player->moveCommited();
}

void Interactor::shoot()
{
	if (!_player->shootStart())
		return;
	_player->changeEnergy(-100);

	EntityContainer *player_container = _field->getPlayerContainer();
	Position damaged_position = calculateSidePosition(player_container->position, _player->getDirection());

	Cell *damaged_cell = _field->getCell(damaged_position);
	if (!damaged_cell->isOccupied())
		return;

	EnemyVector *enemys_container = _field->getEnemysContainer();
	for (int i = 0; i < enemys_container->size(); i++)
	{
		if (damaged_position == enemys_container->at(i).position)
		{
			damaged_cell->entityGone();
			delete enemys_container->at(i).entity;
			enemys_container->erase(enemys_container->begin() + i);

			damaged_cell->setEvent(_field->getEventFacade().getEvent(new AddProgress));
			Cell *random_cell = _field->getCell(_field->getRandomFreePosition());
			random_cell->setEvent(_field->getEventFacade().getEvent(new SpawnEnemy));

			break;
		}
	}
}
