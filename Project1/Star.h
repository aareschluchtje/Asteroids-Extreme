#pragma once

#include "GameObject.h"
#include "ObjModel.h"

class Star : public GameObject
{
public:
	ObjModel *objmodel = new ObjModel("models/star/star.obj");
	Star(int,int,int);
	~Star();
};
