#ifndef ADDPROGRESS_H
#define ADDPROGRESS_H

#include "playerevent.h"

class AddProgress: public PlayerEvent {

public:
	AddProgress(Player *player = nullptr);
	AddProgress(const AddProgress& obj);
	AddProgress& operator=(const AddProgress& obj);

	bool action();

};

#endif
