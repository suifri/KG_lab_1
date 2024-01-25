#pragma once
#include <cstdlib>
#include <GL/glut.h>
#include <ctime>

class ShapeRandomizerService
{
private:
	int maxX;
	int maxY;
	int dividedParts;
	int minX;
	int minY;

public:

	ShapeRandomizerService(int maxX, int maxY, const int dividedParts);
	GLfloat* randomedDots(const int facets);
	int randomedFacetAmount();
	int randomMonitorPart(const int dividedParts) noexcept;
	GLfloat* randomColor();
};

