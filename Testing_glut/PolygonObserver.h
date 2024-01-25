#pragma once
#include "IObserver.h"
#include "ChronoSubject.h"
#include "Polygon.h"
#include "StringRenderService.h"
#include "Tops.h"


class PolygonObserver : public IObserver
{
private:
	std::string subjectMessage;
	ChronoSubject& subject;
	std::list<Shapes::Polygon*> polygonList;
	unsigned maxX;
	unsigned maxY;
	unsigned polygonCounter = 1;
	Tops choice = Tops::RANDOM;

public:
	virtual void update(const std::string& message) override;
	PolygonObserver(ChronoSubject& subject, const unsigned maxX, const unsigned maxY);
	virtual ~PolygonObserver();
	void removeFromList();
	void displayAllPolygons() const;
	void displayAllNames() const;
	void setChoice(const Tops& choice);
};

