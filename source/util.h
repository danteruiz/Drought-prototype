#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

static const float PI = 3.14159;
using namespace std;

namespace util
{
	//returns the angle between two vectors
	float getAngle(sf::Vector2f v1, sf::Vector2f v2);
}

#endif