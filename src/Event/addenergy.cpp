#include "addenergy.h"

AddEnergy::AddEnergy(Player *player) : PlayerEvent(player)
{
}

AddEnergy::AddEnergy(const AddEnergy &obj)
{
	player = obj.player;
}

AddEnergy &AddEnergy::operator=(const AddEnergy &obj)
{
	if (this != &obj)
		player = obj.player;
	return *this;
}

bool AddEnergy::action()
{
	if (player->getEnergyRelation() == 100)
		return false;
	player->changeEnergy(70);
	return true;
}
