#pragma once
#include <string>

class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void update(const std::string& message) = 0;
};

