#define _USE_MATH_DEFINES

#include "Rocket.h"
#include <math.h>
#include <iostream>

Rocket::Rocket(int x, int y, int z) : GameObject()
{
	location[0] = x;
	location[1] = y;
	location[2] = z;
}

void Rocket::Move()
{
	location[0] += speed * sin(rotation[1] / 180 * M_PI);
	location[1] = 0;
	location[2] += speed * cos(rotation[2] / 180 * M_PI);
	std::cout << location[0] << location[1] << location[2] << endl;
}

void Rocket::DriveForward()
{
	speed += 0.05;
}

void Rocket::Brake()
{
	if (speed > 0)
	{
		speed -= 0.05;
	}
}

void Rocket::TurnLeft()
{
	rotation[1] += 0.5;
}

void Rocket::TurnRight()
{
	rotation[1] -= 0.5;
}


Rocket::~Rocket()
{
}
