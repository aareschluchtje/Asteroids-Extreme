#pragma once

#include "GameObject.h"
#include <vector>
#include <array>

class Asteroid : public GameObject
{
public:
	Asteroid(int, int, int);
	~Asteroid();
	void Move() override;
	void Draw();
	float size;
	std::vector<std::array<float,3>> vertices = std::vector<std::array<float, 3>>();
	float speed = 0;
	float rotationOfObject[3] = { 0,0,0 };
	int rotationSpeed = 0;
	float rotationAngle[3] = { 0,0,0 };
};
