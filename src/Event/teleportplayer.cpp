#include "teleportplayer.h"
#include "./../Field/cell.h"
#include "./../Field/field.h"
#include "./../Entity/enemy.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

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
	Position old_player_position = _field->getPlayerContainer()->getPosition();
	Position new_player_position = _field->getRandomFreePosition();
	if (Position(-1, -1) == new_player_position)
		return false;

	_field->getPlayerContainer()->setPosition(new_player_position);
	_field->getCell(old_player_position)->entityGone();
	_field->getCell(new_player_position)->playerStepped();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: TeleportPlayer event; Event: action was accepted;"));
	return true;
}
