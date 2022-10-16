#include "addenergy.h"
#include "./../Entity/Player/player.h"

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
		return false;
	_player->changeEnergy(70);
	return true;
}
