#ifndef EVENT_H
#define EVENT_H

#include "./../Logging/observable.h"

class Event : public Observable
{
public:
	virtual bool action() = 0;
};

#endif
