#include "observable.h"
#include "observer.h"

Observable::Observable()
{
    _observers = new ObserverSet;
}

Observable::~Observable()
{
    delete _observers;
}

void Observable::addObserver(Observer *observer)
{
    _observers->insert(observer);
}

void Observable::removeObserver(Observer *observer)
{
    for (auto elem = _observers->begin(); elem != _observers->end(); elem++)
    {
        if (*elem == observer)
        {
            _observers->erase(elem);
            return;
        }
    }
}

void Observable::notify(std::string message) const
{
    for (auto elem = _observers->begin(); elem != _observers->end(); elem++)
    {
        (*elem)->notify(message);
    }
}
