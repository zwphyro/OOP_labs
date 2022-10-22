#include "addprogress.h"
#include "./../Entity/Player/player.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

AddProgress::AddProgress(Player *player) : PlayerEvent(player)
{
}

AddProgress::AddProgress(const AddProgress &obj)
{
	_player = obj._player;
}

AddProgress &AddProgress::operator=(const AddProgress &obj)
{
	if (this != &obj)
		_player = obj._player;
	return *this;
}

bool AddProgress::action()
{
	_player->changeProgress(3000);
	notify(LogMessage(LogLevels::GAME_ENTITIES, "event AddProgress triggered"));
	return true;
}
