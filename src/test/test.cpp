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
#include <libcloud/2D/Matrix.h>
#include <libcloud/Common/Color.h>
#include <libcloud/Common/Types.h>

int
main (int argc, char** argv)
{
  Matrix<UInt8> M (5, 5);
  M(0,0) = 1;
  M(0,1) = 2;
  M(0,2) = 3;
  M(1,0) = 6;
  M(1,1) = 7;
  M(1,2) = 8;
  M(2,0) = 50;
  M(2,1) = 100;
  M(2,2) = 150;

  Matrix<SInt8> Sx (3, 3);
  Sx(0, 0) = -1;
  Sx(0, 1) = 0;
  Sx(0, 2) = 1;
  Sx(1, 0) = -2;
  Sx(1, 1) = 0;
  Sx(1, 2) = 2;
  Sx(2, 0) = -1;
  Sx(2, 1) = 0;
  Sx(2, 2) = 1;

  for (int i = 0; i < M.getRows (); ++i) {
    for (int j = 0; j < M.getCols (); ++j) {
      std::cout << (SInt16) M(i,j) << ' ';
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << std::endl;

  Matrix<SInt16> Gx = Sx.convolve<SInt16> (M);

  for (Matrix<SInt16>::const_iterator it = Gx.begin (); it != Gx.end (); ++it)
      std::cout << (int) *it << ' ';
  std::cout << std::endl;

  /*clock_t start, end;
  std::cout << "> test start" << std::endl;

  PointCloud cloud;
  OBJReader reader;
  Octree octree (100);
  OctreeIterator it (octree);

  reader.read (argv[1], cloud, false);

  std::cout << "cloud size : " << cloud.size () << std::endl;

  std::cout << "search method comparaison :" << std::endl;
  double linear_time, flann_time;*/

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

  /*start = clock ();
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

  std::cout << "< test end" << std::endl;*/

  return 0;
}