#include "FlannSearch.h"

#include <flann/flann.hpp>

FlannSearch::FlannSearch ()
{
}

FlannSearch::~FlannSearch ()
{
}

void
FlannSearch::setInputCloud (const PointCloud& _cloud)
{
  if (cloud != &_cloud) {
    cloud = &_cloud;
  }
  unsigned int dim = 3; // FIXME

  float *array = new float[cloud->size () * dim * sizeof (float)];

  for (unsigned int i = 0; i < cloud->size (); ++i) {
    array[i * 3] = cloud->at (i).x;
    array[(i * 3) + 1] = cloud->at (i).y;
    array[(i * 3) + 2] = cloud->at (i).y;
  }

  flann::Matrix<float> dataset = flann::Matrix<float> (array, cloud->size (), dim);
  index = new flann::Index<flann::L2<float> > (dataset, flann::AutotunedIndexParams ());
  index->buildIndex ();
}

int
FlannSearch::nearestKSearch (const Point& p, unsigned int k, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances)
{
  PointCloud::const_iterator it;
  unsigned int dim = 3; // FIXME !
  static bool t = false;
  if (!t) {
    setInputCloud (*cloud);
    t = true;
  }
  float query[3] = {p.x, p.y, p.z};
  flann::Matrix<float> query_ (query, 1, 3);

  flann::Matrix<int> indices(new int[query_.rows*k], query_.rows, k);
  flann::Matrix<float> dists(new float[query_.rows*k], query_.rows, k);

  index->knnSearch (query_, indices, dists, k, flann::SearchParams ());
}

int
FlannSearch::radiusSearch (const Point& p, double radius, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances)
{
  
}