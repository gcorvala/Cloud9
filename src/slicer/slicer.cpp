#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Slicers/XYSlicer.h>
#include <iostream>

int
main (int argc, char** argv)
{
  OBJReader reader;
  PointCloud cloud;
  XYSlicer slicer (10, 1024);
  std::vector<PointCloud> result;

  reader.read (argv[1], cloud);

  std::cout << "size:" << cloud.size () << std::endl;
  
  slicer.compute (cloud, result);

  std::cout << "slices:" << result.size () << std::endl;

  return 0;
}
