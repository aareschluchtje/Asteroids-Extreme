#pragma once

#include "GameObject.h"
#include <vector>
#include <array>

class Laser: public GameObject
{
public: 
	Laser(int,int,int,int,int,int,int);
	void Move() override;
	void Draw();
	int speed = 10;
	std::vector<std::array<float, 3>> vertices = std::vector<std::array<float, 3>>();
	~Laser();
};
