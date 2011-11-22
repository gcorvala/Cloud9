#include <iostream>
#include <algorithm>
#include <libcloud/Common/PointCloud.h>
#include <libcloud/Features/NormalEstimator.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Octree/Octree.h>
#include <libcloud/Filters/Filter.h>
#include <libcloud/Filters/TranslateFilter.h>
#include <libcloud/Common/Utils.h>
#include <libcloud/Search/LinearSearch.h>
#include <libcloud/Search/FlannSearch.h>

int
main (int argc, char** argv)
{
  std::cout << "> test start" << std::endl;

  PointCloud cloud;
  OBJReader reader;
  Octree octree (100);
  OctreeIterator it (octree);

  reader.read (argv[1], cloud, false);

  std::cout << "cloud size : " << cloud.size () << std::endl;

  NormalEstimator estimator;
  Search *s = new FlannSearch ();
  s->setInputCloud (cloud);
  estimator.setSearchMethod (*s);

  estimator.setInputCloud (cloud);

  PointCloud out;

  estimator.compute (out);

  std::cout << "< test end" << std::endl;

  return 0;
}