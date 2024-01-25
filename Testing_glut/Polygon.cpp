#include "Polygon.h"

Shapes::Polygon::Polygon(const int maxX, const int maxY, const int dividedParts, const std::string name)
{
	ShapeRandomizerService* service = new ShapeRandomizerService(maxX, maxY, dividedParts);
	this->name = name;
	this->facetAmount = service->randomedFacetAmount();
	this->shapeVertices = service->randomedDots(this->facetAmount);
	this->colorArray = service->randomColor();

	delete service;
	service = nullptr;
}

Shapes::Polygon::Polygon(const int maxX, const int maxY, const int dividedParts, const std::string name, const int facetAmount)
{
	ShapeRandomizerService* service = new ShapeRandomizerService(maxX, maxY, dividedParts);
	this->name = name;
	this->facetAmount = facetAmount;
	this->shapeVertices = service->randomedDots(this->facetAmount);
	this->colorArray = service->randomColor();

	delete service;
	service = nullptr;
}



Shapes::Polygon::Polygon(const int* const facetAmount)
{
	this->name = "First polygon";
	this->facetAmount = *facetAmount;
	this->shapeVertices = new GLfloat[(*facetAmount) * 3];

	for (int i = 0; i < *facetAmount * 3; ++i)
		*(shapeVertices + i) = 10;

	*(shapeVertices) = 10;
	*(shapeVertices + 1) = 50;
	*(shapeVertices + 2) = 0;
	*(shapeVertices + 3) = 50;
	*(shapeVertices + 4) = 150;
	*(shapeVertices + 5) = 0;
	*(shapeVertices + 6) = 250;
	*(shapeVertices + 7) = 25;
	*(shapeVertices + 8) = 0;
}

Shapes::Polygon::Polygon(const int* const facetAmount, const GLfloat* const dotsArray)
{
	this->name = "Second polygon";
	this->facetAmount = *facetAmount;

	this->shapeVertices = new GLfloat[(*facetAmount) * 3];

	for (int i = 0; i < *facetAmount * 3; ++i)
		*(shapeVertices + i) = *(dotsArray + i);
}



void Shapes::Polygon::Display()
{
	glColor3f(*colorArray, *(colorArray + 1), *(colorArray + 2));
	glBegin(GL_POLYGON);

	for (int i = 0; i < facetAmount * 3; i += 3)
		glVertex2f(*(shapeVertices + i), *(shapeVertices + i + 1));

	glEnd();
}

void Shapes::Polygon::setColor(GLfloat r, GLfloat g, GLfloat b) noexcept
{
	*colorArray = r;
	*(colorArray + 1) = g;
	*(colorArray + 2) = b;
}

std::string Shapes::Polygon::getName() const noexcept
{
	return this->name;
}

GLfloat* Shapes::Polygon::getColors() const noexcept
{
	return this->colorArray;
}

int Shapes::Polygon::getFacetAmount() const noexcept
{
	return this->facetAmount;
}

GLfloat* Shapes::Polygon::getDots() const noexcept
{
	return this->shapeVertices;
}
