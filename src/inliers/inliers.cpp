#include <libcloud/Templates/Point2D.h>
#include <libcloud/Templates/Point3D.h>
#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/LineInliers.h>
#include <libcloud/Templates/LineProjector.h>
#include <libcloud/Templates/ExtractIndices.h>
#include <libcloud/Templates/OBJReaderT.h>
#include <libcloud/Templates/XYSlicerT.h>
#include <libcloud/Templates/Hough2D.h>
#include <libcloud/Templates/ExtractHoughClusters.h>
#include <libcloud/Templates/ExtractEuclideanClusters.h>
#include <libcloud/Templates/LinearSearchT.h>

#include <libcloud/Common/PointCloud.h>
#include <libcloud/2D/Line.h>
#include <libcloud/IO/OBJReader.h>

#include <libcloudui/Viewers/Viewer3dWidget.h>
#include <libcloudui/Viewers/ImageViewerWidget.h>
#include <QApplication>

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

template <typename T>
void pointCloudConverter2 (const PointCloudT < Point2D <T> >& input, PointCloud& output)
{
  typename PointCloudT < Point2D <T> >::const_iterator it;

  output.clear ();

  Color c (rand () % 256, rand () % 256, rand () % 256);
  for (it = input.begin (); it != input.end (); ++it) {
    Point p (it->x, it->y, 0);
    p.m_color = c;
    output.push_back (p);
  }
}

template <typename T>
void pointCloudConverter3 (const PointCloudT < Point3D <T> >& input, PointCloud& output)
{
  typename PointCloudT < Point3D <T> >::const_iterator it;

  output.clear ();

  for (it = input.begin (); it != input.end (); ++it) {
    Point p (it->x, it->y, it->z);
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    output.push_back (p);
  }
}

template <typename T>
void pointCloudConverter4 (const PointCloudT < Point3D <T> >& input, PointCloudT < Point2D <T> >& output)
{
  typename PointCloudT < Point3D <T> >::const_iterator it;

  output.clear ();

  for (it = input.begin (); it != input.end (); ++it) {
    output.push_back (Point2D <T> (it->x, it->y));
  }
}

int
main (int argc, char** argv)
{
  QApplication app (argc, argv);

  Viewer3dWidget viewer;

  srand (time (NULL));

  OBJReaderT <Float64> readerT;
  PointCloud cloud;
  PointCloud cloud2;
  PointCloudT < Point3D <double> > cloudT;
  PointCloudT < Point2D <double> > cloudT1;
  PointCloudT < Point2D <double> > cloudT2;
  PointCloudT < Point2D <double> > cloudT3;
  PointCloudT < Point2D <double> > cloudT4;
  std::vector < PointCloudT < Point2D <double> > > clusters;
  LineInliers <double> inliers;
  PointIndices indices;
  ExtractIndices < Point2D <double> > extract;
  LineProjector <double> projector;
  XYSlicerT < Point3D <double> > slicer (20);
  std::vector < PointCloudT < Point3D <double> > > slices;
  Hough2D <double> hough;
  Matrix <UInt32> matrix;
  std::vector <Float64> thetas, rhos;
  ExtractHoughClusters <double> hough_clusters;
  ExtractEuclideanClusters <Point2D <double> > euclidean_clusters;

  readerT.read (argv[1], cloudT);
  std::cout << "cloudT size: " << cloudT.size () << std::endl;

  slicer.compute (cloudT, slices);

  std::cout << "slices size: " << slices.size () << std::endl;
  UInt8 slice_idx = 12;
  std::cout << "slice #20 size: " << slices[slice_idx].size () << std::endl;

  pointCloudConverter3 (slices[slice_idx], cloud);
  
  pointCloudConverter4 <double> (slices[slice_idx], cloudT1);

  hough.setNRho (2048);
  hough.setNTheta (2048);
  hough.compute (cloudT1, matrix, rhos, thetas);

  UInt32 rho, theta, max;

#if 1
  hough_clusters.setAccumulator (matrix);
  hough_clusters.setRhoSteps (rhos);
  hough_clusters.setThetaSteps (thetas);
  hough_clusters.compute (cloudT1, clusters);

  std::cout << "clusters size: " << clusters.size () << std::endl;

  LinearSearchT <Point2D <double> > search;
  std::vector <PointCloudT <Point2D <double> > > clusters_;

  euclidean_clusters.setSearchMethod (search);

  for (UInt32 i = 0; i < clusters.size (); ++i) {
#if 0
    pointCloudConverter2 (clusters[i], cloud2);
    viewer.add ("cluster", &cloud2);
#else
    euclidean_clusters.compute (clusters[i],clusters_);
    std::cout << "clusters_ size: " << clusters_.size () << std::endl;

    for (UInt32 j = 0; j < clusters_.size (); ++j) {
//      std::cout << "clusters_[] size: " << clusters_[j].size () << std::endl;
      pointCloudConverter2 (clusters_[j], cloud2);
      viewer.add ("cluster", &cloud2);
    }
#endif
  }

  viewer.show ();
#else
  matrix.max (theta, rho);
  std::cout << "theta: " << thetas[theta] << std::endl;
  std::cout << "rho: " << rhos[rho] << std::endl;

  Line line (rhos[rho], thetas[theta]);

  //printCloud (cloudT1);

  //Line line (1, -1, -100);

  inliers.setLine (line);
  inliers.setDistanceThreshold (5);

  inliers.compute (cloudT1, indices);

  //printIndices (indices);

  extract.setIndices (indices);
  extract.setNegative (false);
  extract.compute (cloudT1, cloudT2);
  extract.setNegative (true);
  extract.compute (cloudT1, cloudT3);

  std::cout << "cloud size (T2): " << cloudT2.size () << std::endl;

  hough.remove (cloudT2, matrix, rhos, thetas);

  //printCloud (cloudT2);

/*  projector.setLine (line);
  projector.compute (cloudT2, cloudT4);

  //printCloud (cloudT4);

  std::cout << "cloud size: " << cloud.size () << std::endl;
  std::cout << "cloud size: " << cloudT4.size () << std::endl;

  cloudT3 += cloudT4;

  std::cout << "cloud size: " << cloudT3.size () << std::endl;*/

  pointCloudConverter2 (cloudT1, cloud2);

  std::cout << "cloud size: " << cloud2.size () << std::endl;

  viewer.add ("abc", &cloud2);
  //viewer.add ("abc", &cloud);
  viewer.show ();
#endif

  ImageViewerWidget viewer0;
  viewer0.setMatrix (&matrix);
  viewer0.show ();

  return app.exec ();
}