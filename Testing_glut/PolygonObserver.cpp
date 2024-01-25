#include "PolygonObserver.h"

void PolygonObserver::update(const std::string& message)
{
	this->subjectMessage = message;

	if (message == "create")
	{
		if (this->choice == Tops::RANDOM) 
		{
			srand(time(NULL));
			this->polygonList.push_back(new Shapes::Polygon(this->maxX, this->maxY, (rand() % 8) + 1, "Polygon " + std::to_string(this->polygonCounter++)));
		}
		else
		{
			srand(time(NULL));
			this->polygonList.push_back(new Shapes::Polygon(this->maxX, this->maxY, (rand() % 8) + 1, "Polygon " + std::to_string(this->polygonCounter++), static_cast<int>(choice)));
		}
	}
	else if (message == "delete")
		this->polygonList.pop_front();

}

PolygonObserver::PolygonObserver(ChronoSubject& subject, const unsigned maxX, const unsigned maxY)
	:subject(subject), maxX(maxX), maxY(maxY)
{
	this->subject.attach(this);
}

PolygonObserver::~PolygonObserver()
{
}

void PolygonObserver::removeFromList()
{
	subject.detach(this);
}

void PolygonObserver::displayAllPolygons() const
{
	if (this->polygonList.size() > 0)
	{
		for (Shapes::Polygon* pol : this->polygonList)
			pol->Display();
	}
}

void PolygonObserver::displayAllNames() const
{
	if (this->polygonList.size() > 0)
	{
		for (Shapes::Polygon* pol : this->polygonList)
		{
			StringRenderService::renderText(StringRenderService::findXPos(pol->getDots(),
				pol->getFacetAmount()), StringRenderService::findYPos(pol->getDots(), pol->getFacetAmount()),
				GLUT_BITMAP_HELVETICA_12, pol->getName(), pol->getColors());
		}
	}
}

void PolygonObserver::setChoice(const Tops& choice)
{
	this->choice = choice;
}
