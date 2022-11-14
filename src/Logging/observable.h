#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observer;
class LogMessage;
#include <vector>

typedef std::vector<Observer *> ObserverVector;

class Observable
{
public:
    Observable();
    virtual ~Observable() = 0;
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void makeObservable(ObserverVector *observers);
    void makeObservable(Observable &obj);

protected:
    void notify(LogMessage message) const;

private:
    ObserverVector *_observers;
};

#endif
