#pragma once

#include "GameObject.h"
#include "ObjModel.h"

class UFO : public GameObject
{
public:
	UFO(int, int, int);
	void Move(int elapsedtime) override;
	~UFO();
	ObjModel* objmodel = new ObjModel("models/UFO/UFO.obj");
	int speed = 0;
	float rotationOfObject[3] = { 0,0,0 };
};