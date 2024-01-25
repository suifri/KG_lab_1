#include "StringRenderService.h"


void StringRenderService::renderText(GLfloat x, GLfloat y, void* font, const std::string& text,  const GLfloat* const color)
{
	if (color == nullptr)
		std::cout << "Error while setting text color" << std::endl;
	else
		glColor3f(*(color), *(color + 1), *(color + 2));

	glRasterPos2f(x, y);

	for (char c : text)
		glutBitmapCharacter(font, c);
}

GLfloat StringRenderService::findXPos(const GLfloat* const dots, const int facetsAmount)
{
	GLfloat maxX{ 0.0 };

	for (int i = 0; i < facetsAmount * 3; i += 3)
		if (*(dots + i) > maxX)
			maxX = *(dots + i);

	return maxX + 5;
}

GLfloat StringRenderService::findYPos(const GLfloat* const dots, const int facetsAmount)
{
	GLfloat maxY{ 0.0 };
	GLfloat maxX{ 0.0 };

	for (int i = 0; i < facetsAmount * 3; i += 3)
		if (*(dots + i) > maxX)
		{
			maxX = *(dots + i);
			maxY = *(dots + i + 1);
		}

	return maxY + 5;
}


