#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
public:
    virtual void notify(std::string message) = 0;
    virtual ~Observer() = 0;
};

#endif
