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
	void Move() override;
	void DriveForward();
	void Brake();
	void TurnLeft();
	void TurnRight();
	void Up();
	void Down();
	void Teleport();
	Laser Shoot();
	~Rocket();
};
