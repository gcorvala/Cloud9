#include <libcloud/Templates/Point2D.h>
#include <libcloud/Templates/Point3D.h>
#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/LineInliers.h>
#include <libcloud/Templates/LineProjector.h>
#include <libcloud/Templates/ExtractIndices.h>

#include <libcloud/Common/PointCloud.h>
#include <libcloud/2D/Line.h>
#include <libcloud/IO/OBJReader.h>

#include <iostream>

template <class T>
void
printCloud (const PointCloudT <T>& cloud)
{
  typename PointCloudT<T>::const_iterator it;
  std::cout << "printCloud" << std::endl;
  for (it = cloud.begin ();
       it != cloud.end ();
       ++it) {
    std::cout << "point: " << it->x << " " << it->y << std::endl;
  }
}

void
printIndices (const PointIndices& indices)
{
  PointIndices::const_iterator it;
  std::cout << "printIndices" << std::endl;
  for (it = indices.begin (); it != indices.end (); ++it) {
    std::cout << "index: " << *it << std::endl;
  }
}

template <class PointT>
void pointCloudConverter (const PointCloud& input, PointCloudT <PointT>& output)
{
  PointCloud::const_iterator it;

  output.clear ();

  for (it = input.begin (); it != input.end (); ++it) {
    output.push_back (PointT (it->x, it->y));
  }
}

int
main (int argc, char** argv)
{
  OBJReader reader;
  PointCloud cloud;
  PointCloudT < Point2D <double> > cloudT1;
  PointCloudT < Point2D <double> > cloudT2;
  PointCloudT < Point2D <double> > cloudT3;
  LineInliers <double> inliers;
  PointIndices indices;
  ExtractIndices < Point2D <double> > extract;
  LineProjector <double> projector;

  reader.read (argv[1], cloud);

  
  pointCloudConverter < Point2D <double> > (cloud, cloudT1);

  printCloud (cloudT1);

  Line line (0, 1, -50);

  inliers.setLine (line);
  inliers.setDistanceThreshold (3);

  inliers.compute (cloudT1, indices);

  printIndices (indices);

  extract.setIndices (indices);
  extract.setNegative (false);

  extract.compute (cloudT1, cloudT2);

  printCloud (cloudT2);

  projector.setLine (line);
  projector.compute (cloudT2, cloudT3);

  printCloud (cloudT3);

  std::cout << "cloud size: " << cloud.size () << std::endl;
  std::cout << "cloud size: " << cloudT3.size () << std::endl;
}