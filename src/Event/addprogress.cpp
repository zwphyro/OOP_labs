#include "addprogress.h"

AddProgress::AddProgress(Player *player) : PlayerEvent(player)
{
}

AddProgress::AddProgress(const AddProgress &obj)
{
	player = obj.player;
}

AddProgress &AddProgress::operator=(const AddProgress &obj)
{
	if (this != &obj)
		player = obj.player;
	return *this;
}

bool AddProgress::action()
{
	player->changeProgress(100);
	return true;
}
