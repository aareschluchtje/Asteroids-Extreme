#pragma once

#include "GameObject.h"
#include "ObjModel.h"

class Rocket : public GameObject
{
public:
	ObjModel objModel = ObjModel("models/ship/shipA_OBJ.obj");
	float speed = 0;
	Rocket(int,int,int);
	void Move();
	void DriveForward();
	void Brake();
	void TurnLeft();
	void TurnRight();
	~Rocket();
};
