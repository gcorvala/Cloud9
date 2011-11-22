#include "NormalEstimator.h"

#include "../Search/LinearSearch.h"
#include <iostream> // FIXME

NormalEstimator::NormalEstimator ()
{
  k = 36;
  search = new LinearSearch ();
}

NormalEstimator::~NormalEstimator ()
{
}

void
NormalEstimator::compute (PointCloud& output)
{
  PointCloud::const_iterator it;

  search->setInputCloud (*cloud);

  int i = 0;

  for (it = cloud->begin (); it != cloud->end (); ++it) {
    std::vector<unsigned int> indices;
    std::vector<float> sqr_distances;

    search->nearestKSearch (*it, k, indices, sqr_distances);

    std::cout << i++ << std::endl;
  }
}