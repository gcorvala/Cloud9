#include "NormalEstimator.h"

#include "../Search/LinearSearch.h"

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

  for (it = cloud->begin (); it != cloud->end (); ++it) {
    std::vector<unsigned int> indices;
    std::vector<float> sqr_distances;

    search->nearestKSearch (*it, k, indices, sqr_distances);
  }
}