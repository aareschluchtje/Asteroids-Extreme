#include "Star.h"

Star::Star(int x, int y, int z) : GameObject()
{
	location[0] = (float) x;
	location[1] = (float) y;
	location[2] = (float) z;
}

Star::~Star()
{
}
