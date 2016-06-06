#define _USE_MATH_DEFINES

#include "GameWindow.h"
#include "GL\freeglut.h"

GameWindow::GameWindow()
{
	
}

void GameWindow::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (float)windowWidth / windowHeight, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//gluLookAt(0, 2, -5,
	//	0, 0, 0,
	//	0, 1, 0);
	gluLookAt(rocket.location[0] , rocket.location[1] + 20, rocket.location[2]-50,
		rocket.location[0], rocket.location[1], rocket.location[2],
		0, 1, 0);
}

void GameWindow::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glPushMatrix();
	glTranslatef(-rocket.location[0], rocket.location[1], -rocket.location[2]);
	glRotatef(180 + rocket.rotation[1], 0, 1, 0);
	rocket.objModel.draw();
	glTranslatef(rocket.location[0], -rocket.location[1], rocket.location[2]);
	glPopMatrix();
	glFlush();

	glutSwapBuffers();
}
