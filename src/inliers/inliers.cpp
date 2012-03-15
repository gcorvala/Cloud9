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
  for (PointIndices::const_iterator it = indices.begin (); it != indices.end (); ++it) {
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
  PointCloud c;

  reader.read (argv[1], c);

  PointCloudT < Point2D <double> > cloud;
  
  pointCloudConverter < Point2D <double> > (c, cloud);
  
/*  cloud.push_back (Point2D <double> (0, 0));
  cloud.push_back (Point2D <double> (1, 1));
  cloud.push_back (Point2D <double> (0, 2));
  cloud.push_back (Point2D <double> (1, 0));
  cloud.push_back (Point2D <double> (1000, 999));*/

  printCloud (cloud);

  LineInliers <double> inliers;
  Line line (0, 1, -50);

  inliers.setLine (line);
  inliers.setDistanceThreshold (3);

  PointIndices indices;

  inliers.compute (cloud, indices);

  printIndices (indices);

  ExtractIndices < Point2D <double> > extract;
  PointCloudT < Point2D <double> > cloud2;

  extract.setIndices (indices);
  extract.setNegative (false);

  extract.compute (cloud, cloud2);

  printCloud (cloud2);

  LineProjector <double> projector;
  PointCloudT < Point2D <double> > cloud3;

  projector.setLine (line);
  projector.compute (cloud2, cloud3);

  printCloud (cloud3);

  std::cout << "cloud size: " << cloud.size () << std::endl;
  std::cout << "cloud size: " << cloud3.size () << std::endl;
}