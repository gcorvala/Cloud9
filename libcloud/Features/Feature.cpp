#include "Feature.h"

Feature::Feature ()
  : cloud (NULL), search (NULL), k (1), radius (1)
{
}

Feature::~Feature ()
{
}

void
Feature::setInputCloud (const PointCloud& _cloud)
{
  if (cloud != &_cloud) {
    cloud = &_cloud;
  }
  if (search) {
    search->setInputCloud (*cloud);
  }
}

void
Feature::setSearchMethod (Search& _search)
{
  if (search != &_search) {
    search = &_search;
  }
  if (cloud) {
    search->setInputCloud (*cloud);
  }
}

void
Feature::setKSearch (unsigned int _k)
{
  k = _k;
}

void
Feature::setRadiusSearch (double _radius)
{
  radius = _radius;
}