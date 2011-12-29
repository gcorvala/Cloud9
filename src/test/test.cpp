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
#include <libcloud/2D/SobelEstimator.h>
#include <libcloud/Common/Color.h>
#include <libcloud/Common/Types.h>

int
main (int argc, char** argv)
{
  Matrix<UInt8> M (4, 4);
  M(0,0) = 1;
  M(0,1) = 1;
  M(0,2) = 0;
  M(0,3) = 0;
  M(1,0) = 1;
  M(1,1) = 1;
  M(1,2) = 0;
  M(1,3) = 0;
  M(2,0) = 1;
  M(2,1) = 1;
  M(2,2) = 0;
  M(2,3) = 0;
  M(3,0) = 1;
  M(3,1) = 1;
  M(3,2) = 0;
  M(3,3) = 0;

  Matrix<SInt8> kernel1 (3, 3);
  kernel1(0, 0) = -1;
  kernel1(0, 1) = 0;
  kernel1(0, 2) = 1;
  kernel1(1, 0) = -2;
  kernel1(1, 1) = 0;
  kernel1(1, 2) = 2;
  kernel1(2, 0) = -1;
  kernel1(2, 1) = 0;
  kernel1(2, 2) = 1;

  Matrix<SInt8> kernel2 (3, 3);
  kernel2(0, 0) = -1;
  kernel2(0, 1) = -2;
  kernel2(0, 2) = -1;
  kernel2(1, 0) = 0;
  kernel2(1, 1) = 0;
  kernel2(1, 2) = 0;
  kernel2(2, 0) = 1;
  kernel2(2, 1) = 2;
  kernel2(2, 2) = 1;

  Matrix<SInt8> result1;
  M.convolve (kernel1, result1);
  Matrix<SInt8> result2;
  M.convolve (kernel2, result2);
  Matrix<UInt8> gx1;
  result1.mul (result1, gx1);
  Matrix<UInt8> gx2;
  result2.mul (result2, gx2);
  Matrix<UInt8> t = gx1+gx2;
  t.sqrt (t);
  for (Matrix<UInt8>::const_iterator it = t.begin (); it != t.end (); ++it)
      std::cout << (int) *it << ' ';
    std::cout << "\n\n";

  SobelEstimator sobel;

  sobel.setInputMatrix (M);
  Matrix<UInt8> out;
  sobel.compute (out);
  
  for (Matrix<UInt8>::const_iterator it = out.begin (); it != out.end (); ++it)
      std::cout << (int) *it << ' ';
  

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