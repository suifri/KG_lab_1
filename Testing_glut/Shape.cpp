#include "Shape.h"

Shapes::Shape::~Shape()
{
	delete[] this->shapeVertices;
	this->shapeVertices = nullptr;
}
