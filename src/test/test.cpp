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

  TranslateFilter *filter;
  Point min_x, max_x;
  Point min_y, max_y;
  Point min_z, max_z;
  min_x = *min_element (cloud.begin (), cloud.end (), comparePointsByXAxis);
  max_x = *max_element (cloud.begin (), cloud.end (), comparePointsByXAxis);
  min_y = *min_element (cloud.begin (), cloud.end (), comparePointsByYAxis);
  max_y = *max_element (cloud.begin (), cloud.end (), comparePointsByYAxis);
  min_z = *min_element (cloud.begin (), cloud.end (), comparePointsByZAxis);
  max_z = *max_element (cloud.begin (), cloud.end (), comparePointsByZAxis);

  filter = new TranslateFilter (-((max_x + min_x) / 2).x,
                                -((max_y + min_y) / 2).y,
                                -((max_z + min_z) / 2).z);
  filter->run (cloud);

  //for (PointCloud::const_iterator it = cloud.begin (); it != cloud.end (); ++it) {
  //  std::cout << "Point : " << (*it).x << " " << (*it).y << " " << (*it).z << std::endl;
  //}

  std::cout << "end filter" << std::endl;

  NormalEstimator estimator;

  estimator.setInputCloud (cloud);

  PointCloud out;

  estimator.compute (out);

/*  octree.setInputCloud (cloud);
  octree.addPointsFromCloud ();

  std::cout << "octree leafs : " << octree.getLeafCount () << std::endl;

  for (unsigned int x = 0; x < octree.getLeafCount (); ++x) {
    if (*it == NULL) {
      break;
    }
    std::cout << "octree iterator isBranch : " << (*it)->isBranch () << std::endl;
    std::cout << "octree iterator isLeaf : " << (*it)->isLeaf () << std::endl;
    if ((*it)->isLeaf ()) {
      Point point;
      ((OctreeLeafPoint*) (*it))->getData (point);
      std::cout << " Point at : " << point.x << " " << point.y << " " << point.z << std::endl;
    }
    ++it;
  }*/

  std::cout << "< test end" << std::endl;

  return 0;
}