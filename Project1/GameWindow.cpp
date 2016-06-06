#include "GameWindow.h"
#include "GL\freeglut.h"

GameWindow::GameWindow()
{
	objmodels.push_back(new ObjModel("models/ship/shipA_OBJ.obj"));
}

void GameWindow::Setup()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, 1920, 1080);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (float)1920 / 1080, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 1, -50,
		0, 0, 0,
		0, 1, 0);
}

void GameWindow::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glPushMatrix();
	glRotatef(0.25, 1, 0, 0);

	for (ObjModel* model : objmodels)
	{
		model->draw();
	}
	glPopMatrix();
	glFlush();

	glutSwapBuffers();
}
