#include "observable.h"
#include "observer.h"
#include "logmessage.h"

Observable::Observable()
{
    _observers = nullptr;
}

Observable::~Observable()
{
}

void Observable::makeObservable(ObserverSet *observers)
{
    _observers = observers;
}

void Observable::makeObservable(Observable &obj)
{
    _observers = obj._observers;
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
