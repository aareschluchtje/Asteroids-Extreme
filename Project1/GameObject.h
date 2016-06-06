#pragma once
class GameObject
{
public:
	float location[3];
	float rotation[3] = { 0,0,0 };
	GameObject();
	~GameObject();
};

