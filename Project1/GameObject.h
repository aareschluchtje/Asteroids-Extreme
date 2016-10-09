#pragma once

#include <array>

class GameObject
{
public:
	std::array<float, 3> location;
	float rotation[3] = { 0,0,0 };
	GameObject(int, int, int);
	~GameObject();
	virtual void Move(int elapsedtime) = 0;
};

