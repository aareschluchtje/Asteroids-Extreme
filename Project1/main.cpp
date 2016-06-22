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
void SpecialKeyEvent(int, int, int);
void MouseEvent(int, int, int, int);

void Idle(void)
{
	gameWindow->rocket.Move();
	for (unsigned int i = 0; i < gameWindow->asteroids.size(); i++)
	{
		gameWindow->asteroids[i].Move();
	}
	for (unsigned int i = 0; i < gameWindow->ufos.size(); i++)
	{
		gameWindow->ufos[i].Move();
	}
	for (unsigned int i = 0; i < gameWindow->lasers.size(); i++)
	{
		gameWindow->lasers[i].Move();
		for (unsigned int t = 0; t < gameWindow->asteroids.size(); t++)
		{
			if (gameWindow->asteroids[t].checkCollision(gameWindow->lasers[i].location))
			{
				gameWindow->score++;
				gameWindow->asteroids.erase(gameWindow->asteroids.begin() + t);
			}
		}
		if (gameWindow->lasers[i].selfdestruct)
		{
			gameWindow->lasers.erase(gameWindow->lasers.begin() + i);
		}
	}
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

void MouseEvent(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		gameWindow->lasers.push_back(gameWindow->rocket.Shoot());
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
	glutMouseFunc(MouseEvent);
	Init();
	gameWindow = new GameWindow();
	glutMainLoop();
}
