#pragma once

#include "GameObject.h"
#include "ObjModel.h"
#include "Laser.h"

class Rocket : public GameObject
{
public:
	ObjModel objModel = ObjModel("models/ship/shipA_OBJ.obj");
	float speed = 0;
	Rocket(int,int,int);
	void Move(int elapsedtime) override;
	void DriveForward(bool);
	void Brake(bool);
	void TurnLeft(bool);
	void TurnRight(bool);
	void Up(bool);
	void Down(bool);
	void Teleport();
	Laser Shoot();
	~Rocket();
private:
	bool drivingForward = false;
	bool braking = false;
	bool turningLeft = false;
	bool turningRight = false;
	bool goingUp = false;
	bool goingDown = false;
};
