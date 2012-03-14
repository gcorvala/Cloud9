
#include <libcloud/Templates/Point2D.h>
#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/LineInliersT.h>
#include <libcloud/Templates/LineProjectorT.h>

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

int
main ()
{
  PointCloudT < Point2D <double> > cloud;
  PointCloudT < Point2D <double> > cloud_filtered;

  cloud.push_back (Point2D <double> (0, 0));
  cloud.push_back (Point2D <double> (1, 1));
  cloud.push_back (Point2D <double> (0, 2));
  cloud.push_back (Point2D <double> (1, 0));
  cloud.push_back (Point2D <double> (1000, 999));

  printCloud (cloud);

  LineInliersT <double> inliers;

  inliers.setDistanceThreshold (1);

  PointIndices indices;

  inliers.compute (cloud, indices);

  printIndices (indices);

  LineProjectorT <double> projector;

  projector.compute (cloud, cloud_filtered);

  printCloud (cloud_filtered);
}