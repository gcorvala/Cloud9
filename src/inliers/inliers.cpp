#include <libcloud/Templates/Point2D.h>
#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/LineInliersT.h>
#include <libcloud/Templates/LineProjectorT.h>
#include <libcloud/Templates/ExtractIndicesT.h>

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
  PointCloudT < Point2D <double> > cloud2;
  PointCloudT < Point2D <double> > cloud3;

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

  ExtractIndicesT < Point2D <double> > extract;

  extract.setIndices (indices);

  std::cout << "negative" << std::endl;
  extract.setNegative (true);
  extract.compute (cloud, cloud2);

  printCloud (cloud2);

  std::cout << "positive" << std::endl;
  extract.setNegative (false);
  extract.compute (cloud, cloud2);

  printCloud (cloud2);

  LineProjectorT <double> projector;

  projector.compute (cloud2, cloud3);

  printCloud (cloud3);
}