#include <QApplication>
#include <libcloudui/Viewers/ImageViewerWidget.h>

#include <libcloud2/Hough/Accumulator.h>
#include <libcloud2/Hough/AccumulatorVote.h>
#include <libcloud2/Hough/HoughTransform3D.h>
#include <libcloud2/Hough/HoughTransform2D.h>
#include <libcloud2/Common/PointCloud3D.h>
#include <libcloud2/Common/Range.h>
#include <libcloud2/IO/PLYReader.h>
#include <libcloud/2D/Matrix.h>

#include <iostream>
#include <vector>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);
//  try {
    std::vector <Float32> min, max, bin_size;
    std::vector <Float32> maxima_values;
    std::vector < std::vector <UInt32> > maxima_voter_ids;
    Range theta (0, 10, 10);
    Range phi (0, 10, 10);
    Range rho (0, 10, 10);
    std::vector <Range> parameters;
    parameters.push_back (theta);
    parameters.push_back (phi);
    parameters.push_back (rho);
    Matrix <UInt32> mat (1000, 1000);

    Accumulator accu (parameters);
    PointCloud3D cloud;

    QImage image (argv[1]);
    
    for (UInt32 i = 0; i < image.height (); ++i) {
      for (UInt32 j = 0; j < image.width (); ++j) {
        QRgb c = image.pixel (j, i);
        if (qRed (c) < 10)
          cloud += Point3D (i, j, qRed (c));
      }
    }

    /*params.push_back (1);
    params.push_back (2);
    params.push_back (3);
  
    accu.vote (AccumulatorVote (params, 1));
    accu.vote (AccumulatorVote (params, 2));
    params[1] = 3;
    accu.vote (AccumulatorVote (params, 3));
    params[1] = 2;
    accu.vote (AccumulatorVote (params, 4));
    params[1] = 3;
    accu.vote (AccumulatorVote (params, 5));
    accu.vote (AccumulatorVote (params, 6));
    accu.vote (AccumulatorVote (params, 7));
    std::cout << "ok2" << std::endl;*/
    /*for (int i = 0; i < 100; ++i) {
      std::vector <Float32> params;
      params.push_back (1./10.*i);
      params.push_back (1./10.*i);
      params.push_back (1./10.*i);
      accu.vote (AccumulatorVote (params, i));
    }

    accu.findMaxima (3, maxima_values, maxima_voter_ids);*/

    /*for (UInt32 i = 0; i < maxima_values.size (); ++i) {
      std::cout << "max: " << maxima_values[i] << std::endl;
      for (UInt32 j = 0; j < maxima_voter_ids[i].size (); ++j) {
        std::cout << "  id: " << maxima_voter_ids[i][j] << std::endl;
      }
    }*/

    PLYReader reader;

    //reader.read (argv[1], cloud);
    std::cout << "cloud size: " << cloud.size () << std::endl;
  
    HoughTransform2D hough;

    hough.setInput (cloud);
    std::cout << "start hough" << std::endl;
    hough.run ();
    std::cout << "end hough" << std::endl;
    accu = hough.getAccumulator ();
    for (UInt32 i = 0; i < 1000; ++i) {
      for (UInt32 j = 0; j < 1000; ++j) {
        std::vector <UInt32> params;
        params.push_back (i);
        params.push_back (j);
        mat(i,j) = accu.getValue (params);
      }
    }
    ImageViewerWidget viewer0;
    viewer0.setMatrix (&mat);
    viewer0.show ();
    
    std::cout << "start maxima" << std::endl;
    //accu.findMaxima (1, maxima_values, maxima_voter_ids);
    std::cout << "end maxima" << std::endl;
    /*for (UInt32 i = 0; i < maxima_values.size (); ++i) {
      std::cout << "max: " << maxima_values[i] << std::endl;
//      for (UInt32 j = 0; j < maxima_voter_ids[i].size (); ++j) {
//        std::cout << "  id: " << maxima_voter_ids[i][j] << std::endl;
//      }
    }*/
/*  } catch (char const* msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  } catch (std::string& msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  }*/

  return app.exec();
}
