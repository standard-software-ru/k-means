#pragma once

#include "Point.hpp"

class Cluster
{
private:
	int id;
	Point* point;
public:
	Cluster(int id, float x, float y);
	~Cluster();

	int getId();

	Point* getCenter();
	void setCenter(float x, float y);
};