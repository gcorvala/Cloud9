#include <libcloud/Common/PointCloud.h>
#include <libcloud/2D/Matrix.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Slicers/XYSlicer.h>
#include <libcloudui/Viewers/Viewer3dWidget.h>
#include <libcloudui/Viewers/ImageViewerWidget.h>
#include <libcloud/2D/GaussianEstimator.h>
#include <libcloud/2D/HoughEstimator.h>
#include <libcloud/2D/MeanShiftEstimator.h>
#include <libcloud/2D/ImageDrawer.h>
#include <libcloud/2D/ThresholdEstimator.h>
#include <libcloud/Filters/HoughFilter.h>
#include <QApplication>

#include <iostream>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);

  Viewer3dWidget viewer;
  ThresholdEstimator<UInt32> threshold;
  //Viewer3dWidget viewer2;
  OBJReader reader;
  PointCloud cloud;
  XYSlicer slicer (20, 1024);
  std::vector<PointCloud> slices;
  std::vector<PointCloud>::iterator slice_it;
  PointCloud::iterator cloud_it;
  Matrix<UInt8> slice_matrix (1024, 1024);

  reader.read (argv[1], cloud);

  std::cout << "size:" << cloud.size () << std::endl;
  
  slicer.compute (cloud, slices);

  std::cout << "slices:" << slices.size () << std::endl;

  Color color (255, 255, 255);
  for (slice_it = slices.begin (); slice_it != slices.end (); ++slice_it) {
    for (cloud_it = slice_it->begin (); cloud_it != slice_it->end (); ++cloud_it) {
      cloud_it->m_color = color;
    }
    color = Color (color.r-1, color.g-1, color.b-1);
    //viewer.add ("abc", &*slice_it);
  }

  UInt32 slice_id = 12;

/*  HoughFilter hough;
  Plane plane;

//  hough.compute (tmp, cloud, plane);
  hough.compute (slices[slice_id], cloud, plane);

  viewer2.add ("abc", &slices[slice_id]);
  viewer2.add ("abc", &plane);
  viewer2.show ();*/

  Point max = slices[slice_id].getMax ();
  Point min = slices[slice_id].getMin ();

  std::cout << "min:" << min << " max:" << max << std::endl;


  for (cloud_it = slices[slice_id].begin (); cloud_it != slices[slice_id].end (); ++cloud_it) {
    Point m = Vector (max)-Vector (min);
    Point p = Vector (*cloud_it)-Vector (min);
    //qDebug ("1: p.x: %d p.y: %d", (UInt32) p.x, (UInt32) p.y);
    p.x = (p.x/m.x)*1023;
    p.y = (p.y/m.y)*1023;
    p.z = (p.z/m.z)*1023;
    //qDebug ("2: p.x: %d p.y: %d", (UInt32) p.x, (UInt32) p.y);
    slice_matrix ((UInt32) p.x, (UInt32) p.y) = 255;
  }

  Matrix<UInt8>  ms;
//  Matrix<UInt32> param;
  Accumulator<UInt32> param;
  Matrix<UInt32> blurredParam;
  std::vector<Point> modes;
  HoughEstimator hough;
  ImageDrawer drawer (1024, 1024);

  hough.setNTheta (300);
  hough.setNRho (300);

  //hough.compute (slice_matrix, param);
  hough.compute (slices[slice_id], param);
  Matrix<UInt32> t = param;
  threshold.setThreshold (0.05*t.max ());
//  threshold.compute (t, param);
  UInt32 theta, rho;
  Point mm = (Vector (max)-Vector (min))/2;
  std::cout << "center:" << mm << std::endl;
  Float64 m = param.max (theta,rho);
  std::cout << "max: " << theta << " " << rho << std::endl;
  std::cout << "step:" << hough.getRhoStep (slices[slice_id]) << std::endl;
  Float64 h = min.distanceTo (max);
  std::cout << "diag:" << h << std::endl;
//  y-=h;
//  h = sqrt(1024*1024);
  std::cout << "nrho:" << hough.getNRho ()/2 << std::endl;
  Line l (((Float64) rho)*hough.getRhoStep (slices[slice_id])-h, ((Float64) theta*hough.getThetaStep ()));
//  l.translate (mm);
  drawer.drawLine (l, Color (255, 0, 0));
  viewer.add ("abc", &slices[slice_id]);
  viewer.add ("abc", &l);
  GaussianEstimator gaussian;
  //gaussian.setAperture (9);
  gaussian.setSigma (1.8);

  gaussian.compute (param, blurredParam);
  
  MeanShiftEstimator meanShift;

  //viewer.add (Line (500, -M_PI/2));
  //viewer.add (Line (-500, -M_PI/2));
  //viewer.add (Line (500, 0));
  //viewer.add (Line (-500, 0));*/
  //meanShift.compute (blurredParam, ms, modes);
  //meanShift.compute (param, ms, modes);
  
  // 45°
  //drawer.drawLine (Line (1, -1, 0), Color (0, 0, 255));
  // 30°
  //drawer.drawLine (Line (0, -M_PI/3), Color (0, 255, 0));
  // 60°
  //drawer.drawLine (Line (0, -M_PI/6), Color (255, 0, 0));

  for (std::vector<Point>::const_reverse_iterator it = modes.rbegin (); it != modes.rend (); ++it) {
    qDebug ("mode: %d %d %d", it->x, it->y, it->z);
    //Line line (((Float64) y-hough.getNRho ()/2)*hough.getRhoStep (slices[slice_id]), -1./2.*M_PI+((Float64) x*hough.getThetaStep ()));
    //Line line ((it->y-hough.getNRho ()/2)*hough.getRhoStep (slice_matrix), -1./2.*M_PI+(it->x*hough.getThetaStep ()));
    //Line line ((it->y-hough.getNRho ()/2)*hough.getRhoStep (slices[slice_id]), -1./2.*M_PI+(it->x*hough.getThetaStep ()));
    Float64 theta = it->x;
    Float64 rho = it->y;
    Float64 h = min.distanceTo (max);
    //Line line ((rho)*hough.getRhoStep (slices[slice_id])-h, -1./2.*M_PI+(theta*hough.getThetaStep ()));
    Line line (((Float64) rho)*hough.getRhoStep (slices[slice_id])-h, ((Float64) theta*hough.getThetaStep ()));
    //line.translate (-Vector (500, 500));
    drawer.drawLine (line, Color (0, 255, 0));
    viewer.add ("abc", &line);
    std::cout << "line: a:" << line.a << " b:" << line.b << " c:" << line.c << std::endl;
  }

  Image im;

  ImageViewerWidget viewer0;
  viewer0.setMatrix (&slice_matrix);
  viewer0.show ();

  ImageViewerWidget viewer1;
  viewer1.setMatrix (&param);
  viewer1.show ();

  ImageViewerWidget viewer2;
  viewer2.setMatrix (&blurredParam);
  viewer2.show ();

  ImageViewerWidget viewer3;
  viewer3.setMatrix (&ms);
  viewer3.show ();

  ImageViewerWidget viewer4;
  im = drawer.getImage ();
  viewer4.setImage (&im);
  viewer4.show ();

  viewer.show ();

  qDebug ("Modes size: %d", modes.size ());

  return app.exec();
}