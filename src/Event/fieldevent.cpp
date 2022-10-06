#include "fieldevent.h"
#include "./../Field/field.h"

FieldEvent::FieldEvent(Field *field) : field(field)
{
}

void FieldEvent::setField(Field *field)
{
	this->field = field;
}
