#pragma once
class GameObject
{
public:
	float location[3];
	float rotation[3] = { 0,0,0 };
	GameObject(int, int, int);
	~GameObject();
	virtual void Move() = 0;
};

