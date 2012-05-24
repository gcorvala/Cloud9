#if 0
#include "FlannSearch.h"

#include <flann/flann.hpp>
#include <iostream> // FIXME

FlannSearch::FlannSearch ()
{
}

FlannSearch::~FlannSearch ()
{
}

void
FlannSearch::setInputCloud (const PointCloud& _cloud)
{
  std::cout << "set input cloud" << std::endl;
  if (cloud != &_cloud) {
    cloud = &_cloud;
    initIndex ();
  }
}

int
FlannSearch::nearestKSearch (const Point& p, unsigned int k, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances)
{
  PointCloud::const_iterator it;
  unsigned int dim = 3; // FIXME !

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

void
FlannSearch::initIndex ()
{
  std::cout << "init index" << std::endl;
  unsigned int dim = 3; // FIXME

  float* array = new float[cloud->size () * dim * sizeof (float)];

  for (unsigned int i = 0; i < cloud->size (); ++i) { // FIXME : replace by memcpy ?
    array[i * 3] = cloud->at (i).x;
    array[(i * 3) + 1] = cloud->at (i).y;
    array[(i * 3) + 2] = cloud->at (i).y;
  }

  flann::Matrix<float> dataset = flann::Matrix<float> (array, cloud->size (), dim);
  // FIXME : init index directly with array or construct matrix directly ?
  //index = new flann::Index<flann::L2<float> > (dataset, flann::AutotunedIndexParams ());
  index = new flann::Index<flann::L2<float> > (dataset, flann::KDTreeSingleIndexParams ());
  index->buildIndex ();
}
#endif