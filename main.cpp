#include <vector>
#include <utility>
#include <iostream>

#include "Point.hpp"
#include "Cluster.hpp"
#include "KMeans.hpp"

int main()
{
	std::vector<Point*> points = {
		new Point(1, 1),
		new Point(1, 2),
		new Point(2, 3),
		new Point(3, 6),
		new Point(5, 2),
		new Point(7, 2)
	};

	std::vector<Cluster*> clusters = {
		new Cluster(1, 5, 7),
		new Cluster(2, 7, 7)
	};

	KMeans kMeans(points, clusters);
	kMeans.clustering();

	for (const auto point : points)
	{
		std::cout << "Point - " << point->getX() << " " << point->getY() << std::endl;
		std::cout << "Id cluster - " << point->getIdCluster() << std::endl;
	}

	return 0;
}