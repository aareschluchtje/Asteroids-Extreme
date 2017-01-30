#pragma once

#include "GameObject.h"
#include <vector>
#include <array>
#include "ObjModel.h"

class Asteroid : public GameObject
{
public:
	Asteroid(int, int, int);
	int AddVertex(std::array<double, 3> point);
	double getMiddlePoint(double p1, double p2);
	~Asteroid();
	bool checkCollision(array<float,3>);
	void Move(int elapsedtime) override;
	void Draw();
	float size;
	std::vector<std::array<double,3>> vertices = std::vector<std::array<double, 3>>();
	std::vector<std::array<double, 3>> faces = std::vector<std::array<double, 3>>();
	float speed = 0;
	float rotationOfObject[3] = { 0,0,0 };
	int rotationSpeed = 0;
	float rotationAngle[3] = { 0,0,0 };
	GLfloat ambient[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat diffuse[4] = { 0.54509803921f, 0.27058823529f, 0.07450980392f, 1.0f };
	GLfloat emission[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	bool selfdestruct = false;
};
