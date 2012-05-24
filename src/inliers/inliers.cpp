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
void cloud2DTo3D (const PointCloudT < Point2D <T> >& input, PointCloud& output, Float32 z)
{
  typename PointCloudT < Point2D <T> >::const_iterator it;

  output.clear ();

  Color c (rand () % 256, rand () % 256, rand () % 256);
  for (it = input.begin (); it != input.end (); ++it) {
    Point p (it->x, it->y, z);
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

template <typename T>
void cloud3DTo2DXY (const PointCloudT < Point3D <T> >& input, PointCloudT < Point2D <T> >& output)
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
  char* exec = argv[0];
  
  if (argc < 4) {
    std::cerr << "1 Usage : " << exec << " -[xy|xz|yz] thickness input1.obj [input2.obj ...]" << std::endl;
    return -1;
  }

  QApplication app (argc, argv);
  Viewer3dWidget viewer;
  ImageViewerWidget view;

  std::vector < PointCloudT < Point3D <Float32> > > slices;
  std::vector < PointCloudT < Point3D <Float32> > >::const_iterator slice_it;
  OBJReaderT <Float32> reader;
  Hough2D <Float32> hough;
  ExtractHoughClusters <Float32> hough_clusters;

  slices.resize (argc-3);

  for (UInt32 i = 3; i < argc; ++i) {
    std::cout << "reading: " << argv[i] << std::endl;
    reader.read (argv[i], slices[i-3]);
  }

  hough.setNRho (1000);
  hough.setNTheta (720);

  hough_clusters.setDistanceThreshold (10);
  hough_clusters.setMinPointsPerCluster (10);

  for (UInt32 i = 0; i < slices.size (); ++i) {
    Matrix <UInt32> matrix;
    std::vector <Float64> thetas, rhos;
    PointCloudT < Point2D <Float32> > slice;
    std::vector < PointCloudT < Point2D <Float32> > > clusters;
    std::vector <Line> lines;

    std::cout << "slice " << i << " contains " << slices[i].size () << " points" << std::endl;

    cloud3DTo2DXY (slices[i], slice);

    hough.compute (slice, matrix, rhos, thetas);

    view.setMatrix (&matrix);
    view.show ();

    hough_clusters.setAccumulator (matrix);
    hough_clusters.setRhoSteps (rhos);
    hough_clusters.setThetaSteps (thetas);
    hough_clusters.compute (slice, clusters, lines);

    for (UInt32 j = 0; j < clusters.size (); ++j) {
      PointCloud cloud;
      cloud2DTo3D (clusters[j], cloud, i*20);
      viewer.add ("cluster", &cloud);
    }
  }

  viewer.show ();
  
  viewer.raise ();

  return app.exec ();
#if 0
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
#endif
}