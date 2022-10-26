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
	if (_player->getEnergyRelation() == 100)
	{
		notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: AddEnergy event; Event: action was rejected;"));
		return false;
	}

	_player->changeEnergy(2000);
	notify(LogMessage(LogLevels::GAME_ENTITIES, "Object: AddEnergy event; Event: action was accepted;"));
	return true;
}
