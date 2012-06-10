#include <QApplication>
#include <libcloudui/Viewers/ImageViewerWidget.h>

#include <libcloud2/Hough/Accumulator.h>
#include <libcloud2/Hough/HoughTransform3D.h>
#include <libcloud2/Hough/HoughTransform2D.h>
#include <libcloud2/Common/PointCloud3D.h>
#include <libcloud2/Common/Range.h>
#include <libcloud2/IO/PLYReader.h>
#include <libcloud/2D/Matrix.h>

#include <libcloud2/Common/Timer.h>

#include <iostream>
#include <vector>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);
  ImageViewerWidget viewer0;
  QImage image (argv[1]);
  try {
    PLYReader reader;
    PointCloud3D cloud;
    HoughTransform2D hough;
    Matrix <UInt32> mat (hough.getNRho (), hough.getNTheta ());
    std::vector <Float32> min, max, bin_size;
    std::vector <Float32> maxima_values;
    std::vector < std::vector <UInt32> > maxima_voter_ids;
    
    for (UInt32 i = 0; i < image.height (); ++i) {
      for (UInt32 j = 0; j < image.width (); ++j) {
        QRgb c = image.pixel (j, i);
        if (qRed (c) == 0)
          cloud += Point3D (i, j, qRed (c));
      }
    }


    //reader.read (argv[1], cloud);
    PRINT (cloud.size ());
  
    hough.setInput (cloud);
    TIMER (hough.run ());

    const Accumulator& accu = hough.getAccumulator ();
    hough.findMaxima (3, maxima_values, maxima_voter_ids);

    for (UInt32 i = 0; i < hough.getNRho (); ++i) {
      for (UInt32 j = 0; j < hough.getNTheta (); ++j) {
        std::vector <UInt32> params;
        params.push_back (i);
        params.push_back (j);
        mat(i,j) = accu.getValue (params);
      }
    }

    viewer0.setMatrix (&mat);
    viewer0.show ();
    viewer0.raise ();
    
  } catch (char const* msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  } catch (std::string& msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  }

  return app.exec();
}
