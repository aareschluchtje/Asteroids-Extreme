#pragma once

#include "GameObject.h"
#include <vector>
#include <array>

class Laser: public GameObject
{
public: 
	Laser(int,int,int,int,int,int,int);
	void Move(int elapsedtime) override;
	void Draw();
	int speed = 10;
	int distanceTravelled = 0;
	bool selfdestruct = false;
	std::vector<std::array<float, 3>> vertices = std::vector<std::array<float, 3>>();
	~Laser();
};
