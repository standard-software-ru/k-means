#include "Cluster.hpp"

Cluster::Cluster(int id, float x, float y) :
point(new Point(x, y)), id(id)
{
}

Cluster::~Cluster()
{
	delete point;
}

int Cluster::getId()
{
	return id;
}

Point* Cluster::getCenter()
{
	return point;
}

void Cluster::setCenter(float x, float y)
{
	point->setX(x);
	point->setY(y);
}
