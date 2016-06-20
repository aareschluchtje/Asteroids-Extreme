#define _USE_MATH_DEFINES

#include "Rocket.h"
#include <math.h>
#include <iostream>

Rocket::Rocket(int x, int y, int z) : GameObject(x, y, z)
{
}

void Rocket::Move()
{
	location[0] += speed * sin(rotation[1] / 180 * M_PI);
	location[1] += speed * sin(rotation[0] / 180 * M_PI);
	location[2] += speed * cos(rotation[1] / 180 * M_PI);
	std::cout << "x: " << location[0] << "y: " << location[1] << "z: " << location[2] << endl;
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
	rotation[1] += 1;
}

void Rocket::TurnRight()
{
	rotation[1] -= 1;
}

void Rocket::Up()
{
	rotation[0] += 1;
}

void Rocket::Down()
{
	rotation[0] -= 1;
}

void Rocket::Teleport()
{
	location[0] = rand() % 1000 - 500;
	location[1] = rand() % 1000 - 500;
	location[2] = rand() % 1000 - 500;
}

Rocket::~Rocket()
{
	delete &objModel;
}
