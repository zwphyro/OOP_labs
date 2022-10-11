#include "fieldevent.h"
#include "./../Field/field.h"

FieldEvent::FieldEvent(Field *field) : _field(field)
{
}

void FieldEvent::setField(Field *field)
{
	_field = field;
}
