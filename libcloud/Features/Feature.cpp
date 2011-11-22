#include "Feature.h"

Feature::Feature ()
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
}

void
Feature::setSearchMethod (Search& _search)
{
  if (search != &_search) {
    search = &_search;
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