#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Slicers/XYSlicer.h>
#include <libcloudui/Viewers/Viewer3dWidget.h>
#include <QApplication>

#include <iostream>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);

  Viewer3dWidget viewer;
  OBJReader reader;
  PointCloud cloud;
  XYSlicer slicer (10, 1024);
  std::vector<PointCloud> slices;
  std::vector<PointCloud>::iterator slice_it;
  PointCloud::iterator cloud_it;

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
    viewer.add ("abc", &*slice_it);
  }
  viewer.show ();

  return app.exec();
}
