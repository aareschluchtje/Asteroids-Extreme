#define _USE_MATH_DEFINES

#include "Rocket.h"
#include <math.h>
#include <iostream>

Rocket::Rocket(int x, int y, int z) : GameObject(x, y, z)
{
}

void Rocket::Move(int elapsedtime)
{
	location[0] += (float) speed * elapsedtime * sin(rotation[1] / 180 * M_PI);
	location[1] -= (float) speed * elapsedtime * sin(rotation[0] / 180 * M_PI);
	location[2] += (float) speed * elapsedtime * cos((rotation[1] + rotation[0]) / 180 * M_PI);
	//std::cout << "rotation: " << rotation[0] << "speed: " << speed * cos((rotation[1] + rotation[0]) / 180 * M_PI) << endl;
	if(drivingForward)
		speed += 0.001f;
	if (braking)
	{
		if (speed > 0)
		{
			speed -= 0.001f;
		}
	}
	if(turningLeft)
		rotation[1] += 0.1f * elapsedtime;
	if(turningRight)
		rotation[1] -= 0.1f * elapsedtime;
	if (goingUp)
		rotation[0] += 0.1f * elapsedtime;
	if(goingDown)
		rotation[0] -= 0.1f * elapsedtime;
}

void Rocket::DriveForward(bool driving)
{
	drivingForward = driving;
}

void Rocket::Brake(bool brake)
{
	braking = brake;
}

void Rocket::TurnLeft(bool turning)
{
	turningLeft = turning;
}

void Rocket::TurnRight(bool turning)
{
	turningRight = turning;
}

void Rocket::Up(bool turning)
{
	goingUp = turning;
}

void Rocket::Down(bool turning)
{
	goingDown = turning;
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
