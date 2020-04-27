#include "KMeans.hpp"

KMeans::KMeans(std::vector<Point*>& points, std::vector<Cluster*>& clusters)
{
	this->points = points;
	this->clusters = clusters;
}

KMeans::~KMeans()
{
	for (auto& point : points)
	{
		delete point;
	}

	for (auto& cluster : clusters)
	{
		delete cluster;
	}
}

/**
 * Set cluster for point
 */
bool KMeans::setClusterForPoint(Point* point)
{
	float distance = INFINITY;
	float tmpDistance;
	bool foundCluster = false;

	for (auto cluster : clusters)
	{
		tmpDistance = Math::getDistance(point, cluster->getCenter());

		if (tmpDistance < distance)
		{
			point->setIdCluster(cluster->getId());
			distance = tmpDistance;
			foundCluster = true;
		}
	}

	return foundCluster;
}

/**
 * Find all points in cluster
 */
void KMeans::findAllPointsInCluster(Cluster* cluster, std::vector<Point*>& accumulator)
{
	for (auto& point : points)
	{
		if (point->getIdCluster() == cluster->getId())
		{
			accumulator.push_back(point);
		}
	}
}

/**
 * Reposition cluster center
 */
void KMeans::repositionClusterCenter()
{
	for (auto cluster : clusters)
	{
		std::vector<Point*> pointsInCluster;

		findAllPointsInCluster(cluster, pointsInCluster);
		std::vector<float> xCoords;
		std::vector<float> yCoords;

		for (const auto pointInCluster : pointsInCluster)
		{
			xCoords.push_back(pointInCluster->getX());
			yCoords.push_back(pointInCluster->getY());
		}

		cluster->setCenter(Math::means(xCoords), Math::means(yCoords));
	}
}

/**
 * Clustering
 */
void KMeans::clustering()
{
	int iteration = MAX_ITERATION;
	bool wasSetCluster = false;

	while (iteration)
	{
		iteration--;

		for (auto point : points)
		{
			wasSetCluster = setClusterForPoint(point);
		}

		if (!wasSetCluster) break;

		repositionClusterCenter();
	}
}
