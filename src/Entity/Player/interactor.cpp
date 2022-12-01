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

Interactor::Interactor(Field *field) : _field(field)
{
}

Interactor::~Interactor()
{
}

void Interactor::setField(Field *field)
{
	_field = field;
	_player = dynamic_cast<Player *>(field->getPlayerContainer()->getEntity());
}

void Interactor::updatePlayer(int command)
{
	_player->changeEnergy(+500);
	_player->changeProgress(-6);
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

void Interactor::movePlayer(int direction)
{
	if (_player == nullptr || _field == nullptr)
		return;

	if (!_player->moveRequest(direction))
		return;

	EntityContainer *player_container = _field->getPlayerContainer();
	Position new_position = player_container->getPosition().calculateSidePosition(direction, _field->getWidth(), _field->getHeight());

	Cell *new_player_cell = _field->getCell(new_position);
	Cell *old_player_cell = _field->getCell(player_container->getPosition());
	if (new_player_cell->isOccupied())
		return;

	player_container->setPosition(new_position);
	old_player_cell->entityGone();
	new_player_cell->playerStepped();
	_player->moveCommit();
}

void Interactor::shoot()
{
	if (!_player->shootRequest())
		return;
	_player->changeEnergy(-15000);

	EntityContainer *player_container = _field->getPlayerContainer();
	Position damaged_position = player_container->getPosition().calculateSidePosition(_player->getDirection(), _field->getWidth(), _field->getHeight());

	Cell *damaged_cell = _field->getCell(damaged_position);
	WallsPositions *walls_positions = _field->getWallsPositions();
	for (int i = 0; i < walls_positions->size(); i++)
	{
		if (damaged_position == walls_positions->at(i))
		{
			if (!_player->breakWallRequest())
				return;
			_player->changeEnergy(-15000);
			damaged_cell->entityGone();
			walls_positions->erase(walls_positions->begin() + i);

			return;
		}
	}

	while (!damaged_cell->isOccupied())
	{
		damaged_position = damaged_position.calculateSidePosition(_player->getDirection(), _field->getWidth(), _field->getHeight());
		damaged_cell = _field->getCell(damaged_position);
	}

	EnemyVector *enemys_container = _field->getEnemysContainer();
	for (int i = 0; i < enemys_container->size(); i++)
	{
		if (damaged_position == enemys_container->at(i).getPosition())
		{
			damaged_cell->entityGone();
			delete enemys_container->at(i).getEntity();
			enemys_container->erase(enemys_container->begin() + i);

			damaged_cell->setEvent(_field->getEventFacade()->getEvent(new AddProgress));
			Position random_position = _field->getRandomFreePosition();
			if (Position(-1, -1) == random_position)
				return;
			Cell *random_cell = _field->getCell(random_position);
			random_cell->setEvent(_field->getEventFacade()->getEvent(new SpawnEnemy));

			return;
		}
	}
}
