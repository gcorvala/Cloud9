#include "Search.h"

Search::Search ()
{
}

Search::~Search ()
{
}

void
Search::setInputCloud (const PointCloud& _cloud)
{
  if (cloud != &_cloud) {
    cloud = &_cloud;
  }
}
