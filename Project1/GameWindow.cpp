#define _USE_MATH_DEFINES

#include "GameWindow.h"
#include "GL\freeglut.h"
#include <time.h>

void drawScore(float, int, int, std::array<float,3>, bool);
int HeightOfScreen = 0;

GameWindow::GameWindow()
{
	Space::Instance();
}

void GameWindow::Setup(int windowWidth, int windowHeight)
{
	HeightOfScreen = windowHeight;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (float)windowWidth / windowHeight, 0.1, 1000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 0,
		0, 0, 1,
		0, 1, 0);
	glTranslatef(0, -2, 20);
	glRotatef(Space::Instance()->rocket.rotation[0] - 20, 1, 0, 0);
	glRotatef(-Space::Instance()->rocket.rotation[1] - 180, 0, 1, 0);
	glRotatef(Space::Instance()->rocket.rotation[2], 0, 0, 1);
	glTranslatef(Space::Instance()->rocket.location[0], Space::Instance()->rocket.location[1], Space::Instance()->rocket.location[2]);
}

void GameWindow::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	for (Star star : Space::Instance()->stars)
	{
		glPushMatrix();
		glTranslatef(star.location[0], star.location[1], star.location[2]);
		glScalef(200, 200, 200);
		star.objmodel->draw();
		glPopMatrix();
	}
	for (Asteroid asteroid : Space::Instance()->asteroids)
	{
		glPushMatrix();
		asteroid.Draw();
		glPopMatrix();
	}
	for (UFO ufo : Space::Instance()->ufos)
	{
		glPushMatrix();
		glTranslatef(ufo.location[0], ufo.location[1], ufo.location[2]);
		glScalef(20, 20, 20);
		glRotatef(ufo.rotationOfObject[0], 1, 0, 0);
		glRotatef(ufo.rotationOfObject[1], 0, 1, 0);
		glRotatef(ufo.rotationOfObject[2], 0, 0, 1);
		ufo.objmodel->draw();
		glPopMatrix();
	}
	for (Laser laser : Space::Instance()->lasers)
	{
		glPushMatrix();
		glTranslatef(-laser.location[0], -laser.location[1], -laser.location[2]);
		glRotatef(laser.rotation[0], 1, 0, 0);
		glRotatef(laser.rotation[1], 0, 1, 0);
		glRotatef(laser.rotation[2], 0, 0, 1);
		laser.Draw();
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(-Space::Instance()->rocket.location[0], -Space::Instance()->rocket.location[1], -Space::Instance()->rocket.location[2]);
	glRotatef(Space::Instance()->rocket.rotation[1], 0, 1, 0);
	glRotatef(Space::Instance()->rocket.rotation[0], 1, 0, 0);
	Space::Instance()->rocket.objModel.draw();
	glPopMatrix();
	glPushMatrix();
	glLoadIdentity();
	GLfloat position[4] = { -Space::Instance()->rocket.location[0], -Space::Instance()->rocket.location[1] + 10, -Space::Instance()->rocket.location[2], 0};
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glPopMatrix();
	
	drawScore(Space::Instance()->rocket.speed, Space::Instance()->score, fpsvalue, Space::Instance()->rocket.location, showFPS);
	
	glFlush();
	fpscounter++;
	glutSwapBuffers();
}

void drawScore(float speed, int score, int fps, array<float,3> location, bool showFPS)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glEnable(GL_COLOR_MATERIAL);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glOrtho(0, 4000, -50, 2000, 5, -5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	string speedtext = "Speed: " + std::to_string((int) (speed*10000)) + " Km/h";
	for (int i = 0; i < speedtext.length(); i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, speedtext[i]);
	}
	glLoadIdentity();
	glTranslatef(0, 140, 0);
	string scoretext = "Score: " + std::to_string(score);
	for (int i = 0; i < scoretext.length(); i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, scoretext[i]);
	}
	if (showFPS)
	{
		glLoadIdentity();
		glTranslatef(0, 1800, 0);
		string fpstext = std::to_string(fps);
		for (int i = 0; i < fpstext.length(); i++)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, fpstext[i]);
		}
	}
	string locationtext = std::to_string((int)location[0]) + "," + std::to_string((int)location[1]) + "," + std::to_string((int)location[2]);
	glLoadIdentity();
	glTranslatef(4000 - locationtext.length() * 75, 0, 0);
	for (int i = 0; i < locationtext.length(); i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, locationtext[i]);
	}
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
}
