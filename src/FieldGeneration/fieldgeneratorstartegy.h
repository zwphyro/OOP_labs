#ifndef FIELDGENERATORSTRATEGY_H
#define FIELDGENERATORSTRATEGY_H

class Field;
class OptionsParameters;

class FieldGeneratorStrategy
{
public:
    virtual Field *getField(const OptionsParameters *options) = 0;
};

#endif
