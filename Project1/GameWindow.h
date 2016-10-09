#pragma once

#include "ObjModel.h"
#include "Rocket.h"
#include "Star.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Laser.h"

class GameWindow
{
public:
	vector<ObjModel*> objmodels = vector<ObjModel*>();
	vector<Star> stars = vector<Star>();
	vector<Asteroid> asteroids = vector<Asteroid>();
	vector<UFO> ufos = vector<UFO>();
	vector<Laser> lasers = vector<Laser>();
	Rocket rocket = Rocket(0, 0, 0);
	int elapsedTime = 0;
	int lastTime = 0;
	int score = 0;
	int fpscounter = 0;
	int fpsvalue = 0;
	bool showFPS = false;
	GLint mode = GL_FILL;
	GameWindow();
	void Setup(int,int);
	void Draw();
};
