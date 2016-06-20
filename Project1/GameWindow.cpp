#define _USE_MATH_DEFINES

#include "GameWindow.h"
#include "GL\freeglut.h"
#include <time.h>

GameWindow::GameWindow()
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		stars.push_back(Star(rand() % 10000 -5000, rand() % 10000 -5000, rand() % 10000 -5000));
	}
	for (int i = 0; i < 50; i++)
	{
		asteroids.push_back(Asteroid(rand() & 1000 - 500, rand() % 1000 - 500, rand() % 1000 - 500));
	}
}

void GameWindow::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (float)windowWidth / windowHeight, 0.1, 10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(-rocket.location[0] + 50 * sin(rocket.rotation[1] / 180 * M_PI), -rocket.location[1] + 20 * sin(rocket.rotation[0] / 180  * M_PI), -rocket.location[2] + 50 * cos(rocket.rotation[1] / 180 * M_PI) + 50 * cos(rocket.rotation[0] / 180 * M_PI),
		-rocket.location[0], -rocket.location[1], -rocket.location[2],
		0, 1, 0);
}

void GameWindow::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	
	for (Star star : stars)
	{
		glPushMatrix();
		glTranslatef(star.location[0], star.location[1], star.location[2]);
		glScalef(50, 50, 50);
		star.objmodel->draw();
		glPopMatrix();
	}
	for (Asteroid asteroid : asteroids)
	{
		glPushMatrix();
		asteroid.Draw();
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(-rocket.location[0], -rocket.location[1], -rocket.location[2]);
	glRotatef(rocket.rotation[1], 0, 1, 0);
	glRotatef(rocket.rotation[0], 1, 0, 0);
	rocket.objModel.draw();
	glPopMatrix();
	glPushMatrix();
	glLoadIdentity();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glRasterPos2i(50, 50);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 65);
	//const unsigned char *data = (const unsigned char *)"bleh";
	glPopMatrix();
	glFlush();

	glutSwapBuffers();
}
