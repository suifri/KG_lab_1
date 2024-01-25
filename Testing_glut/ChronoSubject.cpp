#include "ChronoSubject.h"

void ChronoSubject::attach(IObserver* observer)
{
	this->listObserver.push_back(observer);
}

void ChronoSubject::detach(IObserver* observer)
{
	this->listObserver.remove(observer);
}

void ChronoSubject::notify()
{
	std::list<IObserver*>::iterator iter = listObserver.begin();

	while (iter != listObserver.end())
	{
		(*iter)->update(this->message);
		++iter;
	}
}

void ChronoSubject::createPolygonTimer()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));

	mut.lock();
	this->message = "create";

	notify();
	mut.unlock();
}

void ChronoSubject::deletePolygonTimer()
{
	std::this_thread::sleep_for(std::chrono::seconds(7));

	mut.lock();
	this->message = "delete";

	notify();
	mut.unlock();
}
