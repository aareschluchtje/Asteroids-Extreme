#pragma once

#include "ObjModel.h"
#include "Star.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Laser.h"
#include "Rocket.h"
#include "SoundTest.h"
#include "Sound.h"

class Space
{
public:
	static Space* Instance();
	void PlayMusic(void);
	void Idle(void);
	vector<ObjModel*> objmodels = vector<ObjModel*>();
	vector<Star> stars = vector<Star>();
	vector<Asteroid> asteroids = vector<Asteroid>();
	vector<UFO> ufos = vector<UFO>();
	vector<Laser> lasers = vector<Laser>();
	Rocket rocket = Rocket(0, 0, 0);
	SoundTest test = SoundTest();
	Sound *music = nullptr;
	Sound *laser = nullptr;
	int elapsedTime = 0;
	int lastTime = 0;
	int score = 0;
	~Space();
private:
	static Space *instance;
	Space();
};