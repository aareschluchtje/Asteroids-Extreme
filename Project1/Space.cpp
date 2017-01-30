#include "Space.h"
#include <time.h>

Space::Space()
{
	music = test.LoadSound("Sound/OdeToJoy(Remix).wav");
	laser = test.LoadSound("Sound/Laser_Gun(short).wav");
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		stars.push_back(Star((rand() % 10000 - 5000) * 20, (rand() % 10000 - 5000) * 20, (rand() % 10000 - 5000) * 20));
	}
	for (int i = 0; i < 50; i++)
	{
		asteroids.push_back(Asteroid(rand() & 2000 - 1000, rand() % 2000 - 1000, rand() % 2000 - 1000));
	}
	for (int i = 0; i < 10; i++)
	{
		ufos.push_back(UFO(rand() & 10000 - 5000, rand() % 10000 - 5000, rand() % 10000 - 5000));
	}
	music->Play();
	laser->Play();
}

Space* Space::instance = nullptr;

Space * Space::Instance()
{
	if (!instance)
	{
		instance = new Space();
	}
	return instance;
}

void Space::PlayMusic(void)
{
	music->Play();
}

void Space::Idle(void)
{
	rocket.Move(elapsedTime);
	for (unsigned int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].Move(elapsedTime);
	}
	for (unsigned int i = 0; i < ufos.size(); i++)
	{
		ufos[i].Move(elapsedTime);
	}
	for (unsigned int i = 0; i < lasers.size(); i++)
	{
		lasers[i].Move(elapsedTime);
		for (unsigned int t = 0; t < asteroids.size(); t++)
		{
			if (asteroids[t].checkCollision(lasers[i].location))
			{
				score++;
				asteroids.erase(asteroids.begin() + t);
			}
		}
		if (lasers[i].selfdestruct)
		{
			lasers.erase(lasers.begin() + i);
		}
	}
	if (asteroids.size() < 1)
	{
		for (int i = 0; i < 50; i++)
		{
			asteroids.push_back(Asteroid(rand() & 2000 - 1000, rand() % 2000 - 1000, rand() % 2000 - 1000));
		}
	}
}

Space::~Space()
{
}
