#ifndef FIELDEVENT_H
#define FIELDEVENT_H

#include "event.h"
class Field;

class FieldEvent : public Event
{
public:
	FieldEvent(Field *field = nullptr);
	void setField(Field *field);

protected:
	Field *_field;
};

#endif
