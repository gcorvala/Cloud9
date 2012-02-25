#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Octree/Octree.h>
#include <iostream>

int
main (int argc, char** argv)
{
  OBJReader reader;
  PointCloud cloud;
  Octree octree (2);
//  Octree::iterator it (octree);

  reader.read (argv[1], cloud);

  std::cout << "size:" << cloud.size () << std::endl;
  
  octree.add (cloud);
//  octree.setInputCloud (cloud);
//  octree.addPointsFromCloud ();

  std::cout << "leafs:" << octree.getLeafCount () << std::endl;

  return 0;
}
