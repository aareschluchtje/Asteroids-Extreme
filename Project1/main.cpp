#include "GL\freeglut.h"
#include "GameWindow.h"

//variable

GLint gameWindowInt;
GameWindow gameWindow = GameWindow();

//function prototypes

void Idle(void);
void PaintComponent(void);
void Reshape(int, int);
void KeyEvent(unsigned char, int, int);

void Idle(void)
{

}

void PaintComponent(void)
{

}

void Reshape(int width, int height)
{

}

void KeyEvent(unsigned char key, int mouseX, int mouseY)
{

}

int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	
	glutInitWindowSize(1920, 1080);
	gameWindowInt = glutCreateWindow("Asteroids Extreme");
	glutIdleFunc(Idle);
	glutDisplayFunc(PaintComponent);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyEvent);
	glutMainLoop();
}