#include <iostream>
#include <algorithm>
#include <time.h>
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
  clock_t start, end;
  std::cout << "> test start" << std::endl;

  PointCloud cloud;
  OBJReader reader;
  Octree octree (100);
  OctreeIterator it (octree);

  reader.read (argv[1], cloud, false);

  std::cout << "cloud size : " << cloud.size () << std::endl;

  std::cout << "search method comparaison :" << std::endl;
  double linear_time, flann_time;

  /*start = clock ();
  NormalEstimator estimator_linear;
  estimator_linear.setInputCloud (cloud);
  end = clock ();
  std::cout << "linear init : " << double (end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

  PointCloud out_linear;

  start = clock ();
  estimator_linear.compute (out_linear);
  end = clock ();
  linear_time = double (end - start) / CLOCKS_PER_SEC;
  std::cout << "compute_linear : " << linear_time << " seconds" << std::endl;*/

  start = clock ();
  NormalEstimator estimator_flann;
  FlannSearch s;
  estimator_flann.setSearchMethod (s);
  estimator_flann.setInputCloud (cloud);
  end = clock ();
  std::cout << "flann init : " << double (end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

  PointCloud out_flann;

  start = clock ();
  estimator_flann.compute (out_flann);
  end = clock ();
  flann_time = double (end - start) / CLOCKS_PER_SEC;
  std::cout << "compute_flann : " << flann_time << " seconds" << std::endl;

  std::cout << "linear vs flann ratio : " << linear_time / flann_time << std::endl;

  std::cout << "< test end" << std::endl;

  return 0;
}