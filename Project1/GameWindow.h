#pragma once

#include "ObjModel.h"

class GameWindow
{
public:
	vector<ObjModel*> objmodels = vector<ObjModel*>();
	GameWindow();
	void Setup();
	void Draw();
};