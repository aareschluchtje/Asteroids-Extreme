#pragma once

#include "ObjModel.h"
#include "Rocket.h"
#include "Star.h"
#include "Asteroid.h"
#include "UFO.h"

class GameWindow
{
public:
	vector<ObjModel*> objmodels = vector<ObjModel*>();
	vector<Star> stars = vector<Star>();
	vector<Asteroid> asteroids = vector<Asteroid>();
	vector<UFO> ufos = vector<UFO>();
	Rocket rocket = Rocket(0, 0, 0);
	GLint mode = GL_FILL;
	GameWindow();
	void Setup(int,int);
	void Draw();
};