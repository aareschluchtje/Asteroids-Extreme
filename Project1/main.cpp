#include "GL\freeglut.h"
#include "GameWindow.h"

//variable

GLint gameWindowInt;
GameWindow *gameWindow = NULL;
int windowWidth, windowHeight;

//function prototypes

void Idle(void);
void Init(void);
void PaintComponent(void);
void Reshape(int, int);
void KeyEvent(unsigned char, int, int);
void SpecialKeyEvent(int, int, int);

void Idle(void)
{
	gameWindow->rocket.Move();
	for (int i = 0; i < gameWindow->asteroids.size(); i++)
	{
		gameWindow->asteroids[i].Move();
	}
	for (int i = 0; i < gameWindow->ufos.size(); i++)
	{
		gameWindow->ufos[i].Move();
	}
	glutPostRedisplay();
}

void Init(void)
{
	windowWidth = 1920;
	windowHeight = 1080;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	glEnable(GL_BLEND);
	GLfloat ambient[4] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	GLfloat diffuse[4] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	GLfloat position[4] = { 5, 5, 0, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void PaintComponent(void)
{
	gameWindow->Setup(windowWidth, windowHeight);
	gameWindow->Draw();
}

void Reshape(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
}

void KeyEvent(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'W':
	case 'w':
		gameWindow->rocket.DriveForward();
		break;
	case 'A':
	case 'a':
		gameWindow->rocket.TurnLeft();
		break;
	case 'S':
	case 's':
		gameWindow->rocket.Brake();
		break;
	case 'D':
	case 'd':
		gameWindow->rocket.TurnRight();
		break;
	case 'Q':
	case 'q':
		gameWindow->rocket.Up();
		break;
	case 'Z':
	case 'z':
		gameWindow->rocket.Down();
		break;
	case ' ':
		gameWindow->rocket.Teleport();
		break;
	case 'T':
	case 't':
		if (gameWindow->mode != GL_LINE)
		{
			gameWindow->mode = GL_LINE;
		}
		else
		{
			gameWindow->mode = GL_FILL;
		}
	}
}

void SpecialKeyEvent(int key, int mouseX, int mouseY)
{
	switch (key)
	{
	case GLUT_KEY_F11:
		glutFullScreenToggle();
		break;
	}
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
	glutSpecialFunc(SpecialKeyEvent);
	Init();
	gameWindow = new GameWindow();
	glutMainLoop();
}
