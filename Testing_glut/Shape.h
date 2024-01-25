#pragma once
#include "IDisplay.h"
#include <GL/glut.h>

namespace Shapes {

	class Shape
	{
	protected:
		GLfloat* shapeVertices;

	public:
		virtual void Display() = 0;
		virtual ~Shape();
	};

}

