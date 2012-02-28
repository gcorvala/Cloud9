#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Filters/CropBoxFilter.h>
#include <libcloud/Filters/HoughFilter.h>
#include <libcloudui/Viewers/Viewer3dWidget.h>
#include <iostream>
#include <QApplication>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);

  OBJReader reader;
  PointCloud cloud;
  PointCloud tmp;
  HoughFilter hough;
  Plane plane;
  Viewer3dWidget viewer;
  //CropBoxFilter crop (Point (500, -10000, 600), Point (1000, 1000, 900));

  reader.read (argv[1], cloud);

  std::cout << "size:" << cloud.size () << std::endl;

  //crop.compute (cloud, tmp);

  std::cout << "size:" << tmp.size () << std::endl;

  hough.compute (cloud, cloud, plane);

  viewer.add ("abc", &cloud);
  viewer.add ("abc", &plane);
  viewer.show ();

  return app.exec();
}
