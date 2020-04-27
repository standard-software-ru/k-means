#pragma once

#include <vector>
#include <cmath>

#include "Point.hpp"

class Math
{
public:
	static float getDistance(Point* one, Point* two);
	static float means(std::vector<float> numbers);
};