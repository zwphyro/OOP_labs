#include "teleportplayer.h"
#include "./../Field/field.h"

TeleportPlayer::TeleportPlayer(Field *field) : FieldEvent(field)
{
}

TeleportPlayer::TeleportPlayer(const TeleportPlayer &obj)
{
	field = obj.field;
}

TeleportPlayer &TeleportPlayer::operator=(const TeleportPlayer &obj)
{
	if (this != &obj)
		field = obj.field;
	return *this;
}

bool TeleportPlayer::action()
{
	Position old_player_position = field->getPlayerContainer()->position;
	Position new_player_position = field->getRandomFreePosition();
	field->getPlayerContainer()->position = new_player_position;
	field->getCell(old_player_position)->entityGone();
	field->getCell(new_player_position)->playerStepped();
	return true;
}
