#include <GL/glut.h>
#include "Polygon.h"
#include <string>
#include "PolygonObserver.h"
#include <mutex>

const int SCREEN_WIDTH = 740;
const int SCREEN_HEIGHT = 580;

void init() {
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

ChronoSubject* sub = new ChronoSubject();
PolygonObserver* obser = new PolygonObserver(*sub, SCREEN_WIDTH, SCREEN_HEIGHT);

void mainMenuHandler(int choice)
{
	switch (choice)
	{
	case 3:
		obser->setChoice(Tops::THREE);
		break;
	case 4:
		obser->setChoice(Tops::FOUR);
		break;
	case 5:
		obser->setChoice(Tops::FIVE);
		break;
	case 6:
		obser->setChoice(Tops::SIX);
		break;
	case 7:
		obser->setChoice(Tops::RANDOM);
		break;
	default:
		exit(0);
		break;
	}
}

void createThread()
{
	while (true)
	{
		sub->createPolygonTimer();
	}
}

void deleteThread()
{
	while (true)
	{
		sub->deletePolygonTimer();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	obser->displayAllPolygons();
	obser->displayAllNames();
	glFlush();
}

void idle()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(740, 580);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Lab 1");
	init();
	std::thread th1(createThread);
	std::thread th2(deleteThread);
	glutIdleFunc(idle);
	glutDisplayFunc(display);

	glutCreateMenu(mainMenuHandler);
	glutAddMenuEntry("3 tops", 3);
	glutAddMenuEntry("4 tops", 4);
	glutAddMenuEntry("5 tops", 5);
	glutAddMenuEntry("6 tops", 6);
	glutAddMenuEntry("Random tops", 7);
	glutAddMenuEntry("Exit", 8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();


	delete obser;
	delete sub;

	return 0;
}