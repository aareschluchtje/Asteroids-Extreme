#define _USE_MATH_DEFINES

#include "Rocket.h"
#include <math.h>
#include <iostream>

Rocket::Rocket(int x, int y, int z) : GameObject(x, y, z)
{
}

void Rocket::Move()
{
	location[0] += (float) speed * sin(rotation[1] / 180 * M_PI);
	location[1] -= (float) speed * sin(rotation[0] / 180 * M_PI);
	location[2] += (float) speed * cos((rotation[1] + rotation[0]) / 180 * M_PI);
	//std::cout << "rotation: " << rotation[0] << "speed: " << speed * cos((rotation[1] + rotation[0]) / 180 * M_PI) << endl;
}

void Rocket::DriveForward()
{
	speed += 0.2f;
}

void Rocket::Brake()
{
	if (speed > 0)
	{
		speed -= 0.2f;
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
	
	location[0] = rand() % 10000 - 5000;
	location[1] = rand() % 10000 - 5000;
	location[2] = rand() % 10000 - 5000;
}

Laser Rocket::Shoot()
{
	Laser laser = Laser(location[0], location[1], location[2], rotation[0], rotation[1], rotation[2], speed);
	return laser;
}

Rocket::~Rocket()
{
	delete &objModel;
}
