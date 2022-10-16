#include "teleportplayer.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Entity/enemy.h"

TeleportPlayer::TeleportPlayer(Field *field) : FieldEvent(field)
{
}

TeleportPlayer::TeleportPlayer(const TeleportPlayer &obj)
{
	_field = obj._field;
}

TeleportPlayer &TeleportPlayer::operator=(const TeleportPlayer &obj)
{
	if (this != &obj)
		_field = obj._field;
	return *this;
}

bool TeleportPlayer::action()
{
	Position old_player_position = _field->getPlayerContainer()->position;
	Position new_player_position = _field->getRandomFreePosition();
	_field->getPlayerContainer()->position = new_player_position;
	_field->getCell(old_player_position)->entityGone();
	_field->getCell(new_player_position)->playerStepped();
	return true;
}
