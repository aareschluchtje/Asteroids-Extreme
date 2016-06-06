#pragma once

#include "ObjModel.h"
#include "Rocket.h"

class GameWindow
{
public:
	vector<ObjModel*> objmodels = vector<ObjModel*>();
	Rocket rocket = Rocket(0, 0, 0);
	GameWindow();
	void Setup(int,int);
	void Draw();
};