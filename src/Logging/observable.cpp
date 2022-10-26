#include "observable.h"
#include "observer.h"
#include "logmessage.h"

Observable::Observable()
{
    _observers = new ObserverVector;
}

Observable::~Observable()
{
    delete _observers;
}

void Observable::addObserver(Observer *observer)
{
    _observers->push_back(observer);
}

void Observable::removeObserver(Observer *observer)
{
    for (int i = 0; i < _observers->size(); i++)
    {
        if (observer == _observers->at(i))
            _observers->erase(_observers->begin() + i);
    }
}

void Observable::makeObservable(ObserverVector *observers)
{
    for (auto elem : *(observers))
        _observers->push_back(elem);
}

void Observable::makeObservable(Observable &obj)
{
    for (auto elem : *(obj._observers))
        _observers->push_back(elem);
}

void Observable::notify(LogMessage message) const
{
    if (!_observers)
        return;

    for (auto elem : *(_observers))
    {
        elem->notify(message);
    }
}
