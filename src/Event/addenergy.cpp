#include "addenergy.h"
#include "./../Entity/Player/player.h"
#include "./../Logging/logmessage.h"
#include "./../Logging/loglevel.h"

AddEnergy::AddEnergy(Player *player) : PlayerEvent(player)
{
}

AddEnergy::AddEnergy(const AddEnergy &obj)
{
	_player = obj._player;
}

AddEnergy &AddEnergy::operator=(const AddEnergy &obj)
{
	if (this != &obj)
		_player = obj._player;
	return *this;
}

bool AddEnergy::action()
{
	_player->fixProgress();
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: AddEnergy event; Event: action was accepted;"));
	return true;
}
