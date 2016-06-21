#define _USE_MATH_DEFINES

#include <math.h>
#include "Laser.h"
#include "ObjModel.h"

Laser::Laser(int x, int y, int z, int rx, int ry, int rz, int speed) : GameObject(x,y,z)
{
	rotation[0] = rx;
	rotation[1] = ry;
	rotation[2] = rz;
	vertices.push_back(std::array<float, 3> {-1, 0, -4});
	vertices.push_back(std::array<float, 3> {1, 0, -4});
	vertices.push_back(std::array<float, 3> {1, 0, 4});
	vertices.push_back(std::array<float, 3> {-1, 0, 4});
	vertices.push_back(std::array<float, 3> {0, -1, -4});
	vertices.push_back(std::array<float, 3> {0, 1, -4});
	vertices.push_back(std::array<float, 3> {0, 1, 4});
	vertices.push_back(std::array<float, 3> {0, -1, 4});
}

void Laser::Move()
{
	location[0] += speed * sin(rotation[1] / 180 * M_PI);
	location[1] += speed * sin(rotation[0] / 180 * M_PI);
	location[2] += speed * cos(rotation[1] / 180 * M_PI);
}

void Laser::Draw()
{
	GLfloat emission[4] = { 0, 0, 1, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);
	}
	glEnd();
}

Laser::~Laser()
{

}
