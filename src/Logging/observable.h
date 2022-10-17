#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observer;
#include <set>
#include <string>

typedef std::set<Observer *> ObserverSet;

class Observable
{
public:
    Observable();
    ~Observable();
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);

protected:
    void notify(std::string message) const;

private:
    ObserverSet *_observers;
};

#endif
