#include "Math.hpp"

float Math::getDistance(Point* one, Point* two)
{
	float xCoord = pow(abs(two->getX() - one->getX()), 2);
	float yCoord = pow(abs(two->getY() - one->getY()), 2);

	return sqrt(xCoord + yCoord);
}

float Math::means(std::vector<float> numbers)
{
	float result = 0;

	for (const auto& number : numbers)
	{
		result += number;
	}

	return result / numbers.size();
}