#pragma once
#include <string>
#include "ShapeRandomizerService.h"
#include "Shape.h"
#include "StringRenderService.h"

namespace Shapes
{
	class Polygon : public Shape
	{
	private:
		int facetAmount;
		std::string name;
		GLfloat* colorArray;
		GLfloat* dots;

	public:

		Polygon(const int maxX, const int maxY, const int dividedParts, const std::string name);
		Polygon(const int maxX, const int maxY, const int dividedParts, const std::string name, const int facetAmount);
		Polygon(const int* const facetAmount);
		Polygon(const int* const facetAmount, const GLfloat* const dotsArray);

		virtual void Display() override;
		void setColor(GLfloat r, GLfloat g, GLfloat b) noexcept;
		std::string getName() const noexcept;
		GLfloat* getColors() const noexcept;
		int getFacetAmount() const noexcept;
		GLfloat* getDots() const noexcept;
	};
}

