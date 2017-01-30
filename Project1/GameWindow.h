#pragma once

#include "ObjModel.h"
#include "Rocket.h"
#include "Star.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Laser.h"
#include "Sound.h"
#include "SoundTest.h"
#include "Space.h"

class GameWindow
{
public:
	int fpscounter = 0;
	int fpsvalue = 0;
	bool showFPS = false;
	GLint mode = GL_FILL;
	GameWindow();
	void Setup(int,int);
	void Draw();
};
