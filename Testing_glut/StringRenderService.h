#pragma once
#include <string>
#include <GL/glut.h>
#include <vector>
#include <iostream>

class StringRenderService
{
public:
	static void renderText(GLfloat x, GLfloat y, void* font, const std::string& text, const GLfloat* const color);

	static GLfloat findXPos(const GLfloat* const dots, const int facetsAmount);
	static GLfloat findYPos(const GLfloat* const dots, const int facetsAmount);
};

