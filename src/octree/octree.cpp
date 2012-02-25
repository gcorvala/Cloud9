#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Octree/Octree.h>
#include <iostream>

int
main (int argc, char** argv)
{
  OBJReader reader;
  PointCloud cloud;
  Octree octree (10);

  reader.read (argv[1], cloud);

  std::cout << "size:" << cloud.size () << std::endl;
  
  octree.add (cloud);

  std::cout << "leafs:" << octree.getLeafCount () << std::endl;

  return 0;
}
