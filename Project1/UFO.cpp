#define _USE_MATH_DEFINES

#include <math.h>
#include "UFO.h"

UFO::UFO(int x, int y, int z) : GameObject(x, y, z)
{
	rotation[1] = (float) (rand() % 360);
	speed = rand() % 10;
}

void UFO::Move()
{
	location[0] += (float) speed * sin(rotation[1] / 180 * M_PI);
	location[2] += (float) speed * cos(rotation[1] / 180 * M_PI);
	rotationOfObject[1] += 1;
}

UFO::~UFO()
{
}
