#ifndef FIELDGENERATOR_H
#define FIELDGENERATOR_H

#include "./../Field/field.h"
#include "./../Interface/Options/optionsparameters.h"
#include "fieldgeneratorstartegy.h"

template <typename... Rules>
class FieldGenerator : public FieldGeneratorStrategy
{
public:
    Field *getField(const OptionsParameters *options);

private:
    template <typename RuleType>
    void applyer(Field *field);
};

template <typename... Rules>
Field *FieldGenerator<Rules...>::getField(const OptionsParameters *options)
{
    Field *field = new Field(options);
    (applyer<Rules>(field), ...);
    return field;
}

template <typename... Rules>
template <typename RuleType>
void FieldGenerator<Rules...>::applyer(Field *field)
{
    RuleType obj;
    obj.apply(field);
}

#endif
