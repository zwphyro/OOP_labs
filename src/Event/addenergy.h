#ifndef ADDENERGY_H
#define ADDENERGY_H

#include "playerevent.h"

class AddEnergy : public PlayerEvent
{
public:
	AddEnergy(Player *player = nullptr);
	AddEnergy(const AddEnergy &obj);
	AddEnergy &operator=(const AddEnergy &obj);

	bool action();
};

#endif
