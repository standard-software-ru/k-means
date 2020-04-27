#pragma once

#include <vector>

#include "Point.hpp"
#include "Cluster.hpp"
#include "Math.hpp"

class KMeans
{
private:
	/**
	 * Max iteration for clustering
	 */
	const int MAX_ITERATION = 1000;

	/**
	 * Points
	 */
	std::vector<Point*> points;

	/**
	 * Clusters
	 */
	std::vector<Cluster*> clusters;
public:
	KMeans(std::vector<Point*>& points, std::vector<Cluster*>& clusters);
	~KMeans();

	/**
	 * Set cluster for point
	 */
	bool setClusterForPoint(Point* point);

	/**
	 * Find all points in cluster
	 */
	void findAllPointsInCluster(Cluster* cluster, std::vector<Point*>& accumulator);

	/**
	 * Reposition cluster center
	 */
	void repositionClusterCenter();

	/**
	 * Clustering
	 */
	void clustering();
};