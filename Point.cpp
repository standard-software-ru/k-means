#include "Point.hpp"

Point::Point(float x, float y, int idCluster) :
x(x), y(y), idCluster(idCluster)
{

}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

void Point::setX(float x)
{
	this->x = x;
}

void Point::setY(float y)
{
	this->y = y;
}

int Point::getIdCluster()
{
	return idCluster;
}

void Point::setIdCluster(int idCluster)
{
	this->idCluster = idCluster;
}