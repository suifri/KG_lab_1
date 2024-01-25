#pragma once
#include "IObserver.h"

class ISubject
{
public:
	virtual ~ISubject() {};

	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify() = 0;
};

