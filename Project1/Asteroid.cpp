#define _USE_MATH_DEFINES

#include "Asteroid.h"
#include <cstdlib>
#include <math.h>
#include <iostream>

Asteroid::Asteroid(int x, int y, int z) : GameObject(x, y, z)
{
	size = rand() % 100 + 10;
	double sizeDividedByOne = 1.0 / (double) size;
	for (int i = 0; i < size; i++)
	{
		for (int t = 0; t < size; t++)
		{
			std::array<double, 3> vertice = std::array<double, 3>();
			vertice[0] = (double)size * sin(-M_PI_2 + M_PI * i * sizeDividedByOne) + (rand() % 10) / size;
			vertice[1] = (double)size * cos(2.0 * (M_PI * t * sizeDividedByOne)) * sin((M_PI * i * sizeDividedByOne)) + (rand() % 10) / size;
			vertice[2] = (double)size * (double)sin(2.0 * M_PI * t * sizeDividedByOne) * sin(M_PI * i * sizeDividedByOne) + (rand() % 10) / size;
			//std::cout << (double)size * cos(2.0 * (M_PI * t * sizeDividedByOne)) * sin((M_PI * i * sizeDividedByOne)) << endl;
			vertices.push_back(vertice);
		}
	}
	//speed = (float) (rand() % 10);
	rotationSpeed = rand() % 10;
	rotation[0] = (float) (rand() % 360);
	rotation[1] = (float) (rand() % 360);
	rotation[2] = (float) (rand() % 360);
	rotationAngle[0] = (float) (rand() % 10);
	rotationAngle[1] = (float) (rand() % 10);
	rotationAngle[2] = (float) (rand() % 10);
}

bool Asteroid::checkCollision(array<float, 3> point) {
	float radius = size;

	float distance = (-Asteroid::location[0] - point[0]) * (-Asteroid::location[0] - point[0]) +
		(-Asteroid::location[1] - point[1]) * (-Asteroid::location[1] - point[1]) +
		(-Asteroid::location[2] - point[2]) * (-Asteroid::location[2] - point[2]);
	distance = sqrt(distance);
	if (distance < radius)
	{
		selfdestruct = true;
		std::cout << "selfdestruct" << endl;
		return true;
	}
	else
	{
		//std::cout << distance << " " << radius << endl;
		return false;
	}
}


Asteroid::~Asteroid()
{
}

void Asteroid::Move()
{
	location[0] += speed * sin(rotation[1] / 180 * M_PI);
	location[1] += speed * sin(rotation[0] / 180 * M_PI);
	location[2] += speed * cos(rotation[1] / 180 * M_PI);
	rotationOfObject[0] += (rotationSpeed * rotationAngle[0]) / 100;
	rotationOfObject[1] += (rotationSpeed * rotationAngle[1]) / 100;
	rotationOfObject[2] += (rotationSpeed * rotationAngle[2]) / 100;
}

void Asteroid::Draw()
{
	glTranslatef(location[0], location[1], location[2]);
	glRotatef(rotationOfObject[0], 1, 0, 0);
	glRotatef(rotationOfObject[1], 0, 1, 0);
	glRotatef(rotationOfObject[2], 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Asteroid::ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Asteroid::diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Asteroid::emission);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUAD_STRIP);
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);
		glNormal3f(0, 0, -1);
	}
	glEnd();
}
