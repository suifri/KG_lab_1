#include "ShapeRandomizerService.h"
#include <iostream>

ShapeRandomizerService::ShapeRandomizerService(int maxX, int maxY, const int dividedParts)
	:dividedParts(dividedParts)
{
	int monitorPart = this->randomMonitorPart(dividedParts);

	this->maxX = (maxX / dividedParts) * monitorPart;
	this->maxY = (maxY / dividedParts) * monitorPart;

	this->minX = this->maxX - (maxX / dividedParts);
	this->minY = this->maxY - (maxY / dividedParts);
}

GLfloat* ShapeRandomizerService::randomedDots(const int facets)
{
	GLfloat* dotsArray{ nullptr };

	dotsArray = new GLfloat[facets * 3];

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	short xCounter{ 0 };
	short yCounter{ 0 };
	short zCounter{ 0 };

	for (int i = 0; i < facets * 3; ++i)
	{
		if (xCounter == 0 || xCounter == zCounter)
		{
			*(dotsArray + i) = static_cast<GLfloat>(std::rand() % (maxX - minX) + minX);

			if (*(dotsArray + i) < 0)
				*(dotsArray + i) *= -1;

			++xCounter;
		}
		else if (yCounter == 0 || yCounter == zCounter)
		{
			*(dotsArray + i) = static_cast<GLfloat>(std::rand() % (maxY - minY) + minY);

			if (*(dotsArray + i) < 0)
				*(dotsArray + i) *= -1;

			++yCounter;
		}
		else if (zCounter == 0 || zCounter < yCounter)
		{
			*(dotsArray + i) = static_cast<GLfloat>(0);
			++zCounter;
		}
		std::cout << *(dotsArray + i) << " ";
	}
	std::cout << std::endl;

	return dotsArray;
}

int ShapeRandomizerService::randomedFacetAmount()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	return rand() % 4 + 3;
}


int ShapeRandomizerService::randomMonitorPart(const int dividedParts) noexcept
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	return std::rand() % dividedParts;
}

GLfloat* ShapeRandomizerService::randomColor()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	GLfloat* colorArray = new GLfloat[3];

	for (int i = 0; i < 3; ++i)
		*(colorArray + i) = static_cast<GLfloat>(std::rand()) / RAND_MAX;

	return colorArray;
}
