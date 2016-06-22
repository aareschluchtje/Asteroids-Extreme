#include "GameObject.h"



GameObject::GameObject(int x, int y, int z)
{
	GameObject::location[0] = x;
	GameObject::location[1] = y;
	GameObject::location[2] = z;
}



GameObject::~GameObject()
{
}
