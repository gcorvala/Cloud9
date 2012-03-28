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
#include <stdlib.h>

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

  OBJReaderT <Float32> reader;
  PointCloud cloud_;
  PointCloudT < Point3D <Float32> > cloud;
  std::vector < PointCloudT < Point2D <Float32> > > clusters;
  std::vector <Line> lines;

  Float32 slice_thickness = atoi (argv[3]);
  XYSlicerT < Point3D <Float32> > slicer (slice_thickness);
  std::vector < PointCloudT < Point3D <Float32> > > slices;
  PointCloudT < Point2D <Float32> > slice;

  Hough2D <Float32> hough;
  Matrix <UInt32> matrix;
  std::vector <Float64> thetas, rhos;

  ExtractHoughClusters <Float32> hough_clusters;
  ExtractEuclideanClusters <Point2D <Float32> > euclidean_clusters;

  reader.read (argv[1], cloud);
  std::cout << "cloud size: " << cloud.size () << std::endl;

  slicer.compute (cloud, slices);

  std::cout << "slices size: " << slices.size () << std::endl;

  UInt8 slice_idx = atoi (argv[2]);
  pointCloudConverter4 (slices[slice_idx], slice);
  std::cout << "slice #" << (int) slice_idx << " size: " << slice.size () << std::endl;
  

  hough.setNRho (2000);
  hough.setNTheta (720);
  hough.compute (slice, matrix, rhos, thetas);

  UInt32 rho, theta, max;

  hough_clusters.setDistanceThreshold (10);
  hough_clusters.setMinPointsPerCluster (10);
  hough_clusters.setAccumulator (matrix);
  hough_clusters.setRhoSteps (rhos);
  hough_clusters.setThetaSteps (thetas);
  hough_clusters.compute (slice, clusters, lines);

  std::cout << "clusters size: " << clusters.size () << std::endl;

  ImageViewerWidget v;
  for (UInt32 i = 0; i < clusters.size (); ++i) {
    std::cout << "i: " << i << std::endl;
    /*Hough2D <Float32> h;
    h.setNRho (20000);
    h.setNTheta (180);

    rhos.clear (); thetas.clear ();
    h.compute (clusters[i], matrix, rhos, thetas);
    v.setMatrix (&matrix);
    v.show ();
    UInt32 rho, theta;
    matrix.max (theta, rho);
    Line l;
    l = Line (rhos[rho], thetas[theta]);*/
    LineProjector <Float32> projector;
    projector.setLine (lines[i]);
    //projector.setLine (l);
    PointCloudT < Point2D <Float32> > cloud_projected;
    projector.compute (clusters[i], cloud_projected);
    //viewer.add ("ok", &l);
    pointCloudConverter2 (clusters[i], cloud_);
    //pointCloudConverter2 (cloud_projected, cloud_);
    viewer.add ("cluster", &cloud_);
    //if (i==2) break;
  }

  viewer.show ();
  
  viewer.raise ();

  return app.exec ();
}