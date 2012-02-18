#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Filters/HoughFilter.h>
#include <iostream>

int
main (int argc, char** argv)
{
  OBJReader reader;
  PointCloud cloud;
  HoughFilter hough;

  reader.read (argv[1], cloud);

  std::cout << "size:" << cloud.size () << std::endl;

  hough.compute (cloud, cloud);

  return 0;
}
