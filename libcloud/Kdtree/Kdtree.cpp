#include "Kdtree.h"

#include <algorithm>

Kdtree::Kdtree ()
  :root (NULL)
{
}

Kdtree::~Kdtree ()
{
  delete root;
}

void
Kdtree::setInputCloud (const PointCloud& _cloud)
{
  if (cloud != &_cloud) {
    cloud = &_cloud;
  }
}

void
Kdtree::addPointsFromCloud ()
{
  // FIXME : try to create the tree without recursive methods !
  // into the Kdtree class because avoid vector duplications (using indices)
  std::vector<Point> points;
  points.resize (cloud->size ());
  std::copy (cloud->begin (), cloud->end (), points.begin ());
  root = new KdtreeNode (points);
}

const Point&
Kdtree::nearestSearch (unsigned int index) const
{
  KdtreeNode* current;

  current = root;

  if (&current->getLeftChild () && &current->getRightChild ()) {
    Point median = current->getMedian ();
  }

  return cloud->at (0);
}

/*unsigned int
Kdtree::nearestKSearch (unsigned int index, unsigned int k, std::vector<unsigned int>& indices, std::vector<double>& distances)
{
}*/