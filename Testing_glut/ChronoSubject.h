#pragma once
#include "ISubject.h"
#include <list>
#include <thread>
#include <mutex>

class ChronoSubject : public ISubject
{
private:
	std::list<IObserver*> listObserver;
	std::string message;
	std::mutex mut;
public:
	virtual ~ChronoSubject() {};
	virtual void attach(IObserver* observer) override;
	virtual void detach(IObserver* observer) override;
	virtual void notify() override;
	void createPolygonTimer();
	void deletePolygonTimer();
};

