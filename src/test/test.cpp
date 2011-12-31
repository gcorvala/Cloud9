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
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/SobelEstimator.h>
#include <libcloud/Common/Color.h>
#include <libcloud/Common/Types.h>

int
main (int argc, char** argv)
{
  Matrix<UInt8> M (4, 4);
  M(0,0) = 255;
  M(0,1) = 255;
  M(0,2) = 0;
  M(0,3) = 0;
  M(1,0) = 255;
  M(1,1) = 255;
  M(1,2) = 0;
  M(1,3) = 0;
  M(2,0) = 255;
  M(2,1) = 255;
  M(2,2) = 0;
  M(2,3) = 0;
  M(3,0) = 255;
  M(3,1) = 255;
  M(3,2) = 0;
  M(3,3) = 0;

  SobelEstimator sobel;

  sobel.setInputMatrix (M);
  Matrix<UInt8> out;
  sobel.compute (out);
  
  for (Matrix<UInt8>::const_iterator it = out.begin (); it != out.end (); ++it)
      std::cout << (int) *it << ' ';

  return 0;
}