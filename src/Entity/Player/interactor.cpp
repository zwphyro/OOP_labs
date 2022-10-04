#include "interactor.h"
#include "player.h"
#include "./../../Field/field.h"

Interactor::Interactor(Field *field, Player *player) : field(field), player(player)
{
}

Interactor::~Interactor()
{
	if (player)
		delete player;
}

void Interactor::setPlayer(Player *player)
{
	this->player = player;
}

void Interactor::setField(Field *field)
{
	this->field = field;
}

void Interactor::updatePlayer(int command)
{
	if (player->getProgressRelation() == 100 || player->getProgressRelation() == 0)
		return;

	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT,
		SHOOT
	};

	player->changeEnergy();
	player->changeProgress();
	player->changeSpeed();

	switch (command)
	{
	case UP:
	case DOWN:
	case LEFT:
	case RIGHT:
		movePlayer(command);
		break;
	case SHOOT:
		shoot();
		break;
	default:
		break;
	}
}

Position Interactor::calculateSidePosition(Position position, int direction)
{
	enum
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	int old_x = position.x;
	int old_y = position.y;
	int new_x, new_y;

	switch (direction)
	{
	case UP:
		new_x = old_x;
		new_y = (old_y - 1 + field->getHeight()) % field->getHeight();
		break;
	case DOWN:
		new_x = old_x;
		new_y = (old_y + 1) % field->getHeight();
		break;
	case RIGHT:
		new_x = (old_x + 1) % field->getWidth();
		new_y = old_y;
		break;
	case LEFT:
		new_x = (old_x - 1 + field->getWidth()) % field->getWidth();
		new_y = old_y;
		break;
	}

	return {new_x, new_y};
}

void Interactor::movePlayer(int direction)
{
	if (player == nullptr || field == nullptr)
		return;

	if (!player->moveStart(direction))
		return;

	EntityContainer *player_container = field->getPlayerContainer();
	Position new_position = calculateSidePosition(player_container->position, direction);

	Cell *new_player_cell = field->getCell(new_position);
	Cell *old_player_cell = field->getCell(player_container->position);
	if (new_player_cell->isOccupied())
		return;

	player_container->position = new_position;
	new_player_cell->playerStepped();
	old_player_cell->entityGone();
	player->moveCommited();
}

void Interactor::shoot()
{
	if (!player->shootStart())
		return;
	player->changeEnergy(-100);

	EntityContainer *player_container = field->getPlayerContainer();
	Position damaged_position = calculateSidePosition(player_container->position, player->getDirection());

	Cell *damaged_cell = field->getCell(damaged_position);
	if (!damaged_cell->isOccupied())
		return;

	EnemyVector *enemys_container = field->getEnemysContainer();
	for (int i = 0; i < enemys_container->size(); i++)
	{
		if (damaged_position == enemys_container->at(i).position)
		{
			damaged_cell->entityGone();
			delete enemys_container->at(i).entity;
			enemys_container->erase(enemys_container->begin() + i);

			damaged_cell->setEvent(field->getFactory().createEvent(new AddProgress));
			Cell *random_cell = field->getCell(field->getRandomFreePosition());
			random_cell->setEvent(field->getFactory().createEvent(new SpawnEnemy));

			break;
		}
	}
}
