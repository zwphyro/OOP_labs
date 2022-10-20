#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observer;
class LogMessage;
#include <set>
#include <string>

typedef std::set<Observer *> ObserverSet;

class Observable
{
public:
    Observable();
    virtual ~Observable() = 0;
    void makeObservable(ObserverSet *observers);
    void makeObservable(Observable &obj);

protected:
    void notify(LogMessage message) const;

private:
    ObserverSet *_observers;
};

#endif
