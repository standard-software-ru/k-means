#pragma once

class Point
{
private:
	float x;
	float y;

	int idCluster;
public:
	Point(float x, float y, int idCluster = 0);

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	int getIdCluster();
	void setIdCluster(int idCluster);
};