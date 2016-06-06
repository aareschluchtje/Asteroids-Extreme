#include "GL\freeglut.h"
#include "GameWindow.h"

//variable

GLint gameWindowInt;
GameWindow *gameWindow = NULL;

//function prototypes

void Idle(void);
void Init(void);
void PaintComponent(void);
void Reshape(int, int);
void KeyEvent(unsigned char, int, int);

void Idle(void)
{
	glutPostRedisplay();
}

void Init(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	GLfloat position[4] = { 5, 0, 0, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void PaintComponent(void)
{
	gameWindow->Setup();
	gameWindow->Draw();
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
	Init();
	gameWindow = new GameWindow();
	glutMainLoop();
}
