#define _USE_MATH_DEFINES

#include "Asteroid.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <map>

std::map<long, double> middlePointIndexCache;
int index = 0;

Asteroid::Asteroid(int x, int y, int z) : GameObject(x, y, z)
{
	size = (float) (rand() % 100 + 10);

	// create 12 vertices of a icosahedron
	double t = 1.0 + sqrt(5.0) / 2.0;

	AddVertex({ -1, t, 0 });
	AddVertex({ 1, t, 0 });
	AddVertex({ -1, -t, 0 });
	AddVertex({ 1, -t, 0 });

	AddVertex({ 0, -1, t });
	AddVertex({ 0, 1, t });
	AddVertex({ 0, -1, -t });
	AddVertex({ 0, 1, -t });

	AddVertex({ t, 0, -1 });
	AddVertex({ t, 0, 1 });
	AddVertex({ -t, 0, -1 });
	AddVertex({ -t, 0, 1 });

	// create 20 triangles of the icosahedron

	// 5 faces around point 0
	faces.push_back({ 0, 11, 5 });
	faces.push_back({ 0, 5, 1 });
	faces.push_back({ 0, 1, 7 });
	faces.push_back({ 0, 7, 10 });
	faces.push_back({ 0, 10, 11 });

	// 5 adjacent faces
	faces.push_back({ 1, 5, 9 });
	faces.push_back({ 5, 11, 4 });
	faces.push_back({ 11, 10, 2 });
	faces.push_back({ 10, 7, 6 });
	faces.push_back({ 7, 1, 8 });

	// 5 faces around point 3
	faces.push_back({ 3, 9, 4 });
	faces.push_back({ 3, 4, 2 });
	faces.push_back({ 3, 2, 6 });
	faces.push_back({ 3, 6, 8 });
	faces.push_back({ 3, 8, 9 });

	// 5 adjacent faces
	faces.push_back({ 4, 9, 5 });
	faces.push_back({ 2, 4, 11 });
	faces.push_back({ 6, 2, 10 });
	faces.push_back({ 8, 6, 7 });
	faces.push_back({ 9, 8, 1 });

	for (int i = 0; i < 3; i++)
	{
		std::vector<std::array<double, 3>> faces2 = std::vector<std::array<double, 3>>();
		for(std::array<double,3> tri : faces)
		{
			double a = getMiddlePoint(tri[0], tri[1]);
			double b = getMiddlePoint(tri[1], tri[2]);
			double c = getMiddlePoint(tri[2], tri[0]);

			faces2.push_back({ tri[0], a, c });
			faces2.push_back({ tri[1], b, a });
			faces2.push_back({ tri[2], c, b });
			faces2.push_back({ a, b, c });
		}
		faces = faces2;
	}

	//for (int i = 0; i < size; i++)
	//{
	//	for (int t = 0; t < size; t++)
	//	{
	//		std::array<double, 3> vertice = std::array<double, 3>();
	//		vertice[0] = (double)size * sin(-M_PI_2 + M_PI * i * sizeDividedByOne) + (rand() % 10) / size;
	//		vertice[1] = (double)size * cos(2.0 * (M_PI * t * sizeDividedByOne)) * sin((M_PI * i * sizeDividedByOne)) + (rand() % 10) / size;
	//		vertice[2] = (double)size * (double)sin(2.0 * M_PI * t * sizeDividedByOne) * sin(M_PI * i * sizeDividedByOne) + (rand() % 10) / size;
	//		//std::cout << (double)size * cos(2.0 * (M_PI * t * sizeDividedByOne)) * sin((M_PI * i * sizeDividedByOne)) << endl;
	//		vertices.push_back(vertice);
	//	}
	//}
	speed = ((float) (rand() % 10)) / 20;
	rotationSpeed = rand() % 10;
	rotation[0] = (float) (rand() % 360);
	rotation[1] = (float) (rand() % 360);
	rotation[2] = (float) (rand() % 360);
	rotationAngle[0] = (float) (rand() % 10);
	rotationAngle[1] = (float) (rand() % 10);
	rotationAngle[2] = (float) (rand() % 10);
}

int Asteroid::AddVertex(std::array<double, 3> point)
{
	double length = sqrt(point[0] * point[0] + point[1] * point[1] + point[2] * point[2]);
	vertices.push_back({point[0] / length, point[1] / length, point[2] / length});
	return index++;
}

double Asteroid::getMiddlePoint(double p1, double p2)
{
	bool firstIsSmaller = p1 < p2;
	long smallerIndex = firstIsSmaller ? p1 : p2;
	long greaterIndex = firstIsSmaller ? p2 : p1;
	long key = (smallerIndex << 32) + greaterIndex;

	if (middlePointIndexCache.find(key) != middlePointIndexCache.end())
	{
		return middlePointIndexCache.find(key)->second;
	}

	std::array<double, 3> point1 = vertices[p1];
	std::array<double, 3> point2 = vertices[p2];
	std::array<double, 3> middle = {
		(point1[0] + point2[0]) / 2.0,
		(point1[1] + point2[1]) / 2.0,
		(point1[2] + point2[2]) / 2.0};

	double i = AddVertex(middle);

	middlePointIndexCache.insert(std::pair<long, double>(key, i));
	return i;
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

void Asteroid::Move(int elapsedtime)
{
	location[0] += (speed * elapsedtime) * sin(rotation[1] / 180 * M_PI);
	location[1] += (speed * elapsedtime) * sin(rotation[0] / 180 * M_PI);
	location[2] += (speed * elapsedtime) * cos(rotation[1] / 180 * M_PI);
	rotationOfObject[0] += (rotationSpeed * elapsedtime * rotationAngle[0]) / 1000;
	rotationOfObject[1] += (rotationSpeed * elapsedtime * rotationAngle[1]) / 1000;
	rotationOfObject[2] += (rotationSpeed * elapsedtime * rotationAngle[2]) / 1000;
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
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		//std::cout << vertices[i][0] << endl;
		glVertex3f(vertices[faces[i][0]][0] * size, vertices[faces[i][0]][1] * size, vertices[faces[i][0]][2] * size);
		glVertex3f(vertices[faces[i][1]][0] * size, vertices[faces[i][1]][1] * size, vertices[faces[i][1]][2] * size);
		glVertex3f(vertices[faces[i][2]][0] * size, vertices[faces[i][2]][1] * size, vertices[faces[i][2]][2] * size);
		glNormal3f(0, 0, -1);
	}
	glEnd();
}
