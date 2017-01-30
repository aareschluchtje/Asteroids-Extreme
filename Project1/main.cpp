#include "GL\freeglut.h"
#include "GameWindow.h"
#include <ctime>

//variable

GLint gameWindowInt;
GameWindow *gameWindow = NULL;
int windowWidth, windowHeight;
int lastTime = time(NULL);

//function prototypes

void Idle(void);
void Init(void);
void PaintComponent(void);
void Reshape(int, int);
void KeyEvent(unsigned char, int, int);
void KeyEventUp(unsigned char, int, int);
void SpecialKeyEvent(int, int, int);
void MouseEvent(int, int, int, int);

void Idle(void)
{
	Space::Instance()->Idle();
	if (lastTime != time(NULL))
	{
		lastTime = time(NULL);
		gameWindow->fpsvalue = gameWindow->fpscounter;
		gameWindow->fpscounter = 0;
	}
	else
	{
		gameWindow->fpscounter++;
	}
	int timenow = glutGet(GLUT_ELAPSED_TIME);
	Space::Instance()->elapsedTime = timenow - Space::Instance()->lastTime;
	Space::Instance()->lastTime = timenow;
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
		Space::Instance()->rocket.DriveForward(true);
		break;
	case 'A':
	case 'a':
		Space::Instance()->rocket.TurnLeft(true);
		break;
	case 'S':
	case 's':
		Space::Instance()->rocket.Brake(true);
		break;
	case 'D':
	case 'd':
		Space::Instance()->rocket.TurnRight(true);
		break;
	case 'Q':
	case 'q':
		Space::Instance()->rocket.Up(true);
		break;
	case 'Z':
	case 'z':
		Space::Instance()->rocket.Down(true);
		break;
	case 'M':
	case 'm':
		Space::Instance()->PlayMusic();
		break;
	case ' ':
		Space::Instance()->rocket.Teleport();
		break;
	case 'F':
	case 'f':
		gameWindow->showFPS = !gameWindow->showFPS;
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

void KeyEventUp(unsigned char key, int width, int height)
{
	switch (key)
	{
	case 'W':
	case 'w':
		Space::Instance()->rocket.DriveForward(false);
		break;
	case 'A':
	case 'a':
		Space::Instance()->rocket.TurnLeft(false);
		break;
	case 'S':
	case 's':
		Space::Instance()->rocket.Brake(false);
		break;
	case 'D':
	case 'd':
		Space::Instance()->rocket.TurnRight(false);
		break;
	case 'Q':
	case 'q':
		Space::Instance()->rocket.Up(false);
		break;
	case 'Z':
	case 'z':
		Space::Instance()->rocket.Down(false);
		break;
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

void MouseEvent(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		Space::Instance()->laser->Play();
		Space::Instance()->lasers.push_back(Space::Instance()->rocket.Shoot());
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
	glutKeyboardUpFunc(KeyEventUp);
	glutSpecialFunc(SpecialKeyEvent);
	glutMouseFunc(MouseEvent);
	Init();
	gameWindow = new GameWindow();
	glutMainLoop();
}
