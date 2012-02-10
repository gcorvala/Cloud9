#include <QApplication>

#include <libcloudui/Viewers/ImageViewerWidget.h>
#include <libcloud/2D/CannyEstimator.h>
#include <libcloud/2D/GaussianEstimator.h>
#include <libcloud/2D/HoughEstimator.h>
#include <libcloud/2D/MeanShiftEstimator.h>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);
  QImage image (argv[1]);
  Image im;
  im.resize (image.height (), image.width ());

  for (UInt32 i = 0; i < image.height (); ++i) {
    for (UInt32 j = 0; j < image.width (); ++j) {
      QRgb c = image.pixel (j, i);
      im.setPixel (i, j, Color (qRed (c), qGreen (c), qBlue (c)));
    }
  }

  Matrix<UInt8> red = im.getYChannel ();
  Matrix<UInt8> edge, modes;
  Matrix<UInt32> param;
  Matrix<UInt32> blurredParam;

  CannyEstimator canny;

  canny.compute (red, edge);

  HoughEstimator hough;

  hough.setNTheta (800);
  hough.setNRho (800);

  hough.compute (edge, param);

  GaussianEstimator gaussian;
  gaussian.setAperture (9);
  gaussian.setSigma (5.3);

  gaussian.compute (param, blurredParam);
  
  MeanShiftEstimator meanShift;

  meanShift.compute (blurredParam, modes);

  ImageViewerWidget viewer1;
  viewer1.setMatrix (&param);
  viewer1.show ();

  ImageViewerWidget viewer2;
  viewer2.setMatrix (&blurredParam);
  viewer2.show ();

  ImageViewerWidget viewer3;
  viewer3.setMatrix (&modes);
  viewer3.show ();

  return app.exec();
}
