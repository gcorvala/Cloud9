#include <QApplication>

#include <libcloudui/Viewers/ImageViewerWidget.h>
#include <libcloud/2D/CannyEstimator.h>
#include <libcloud/2D/GaussianEstimator.h>
#include <libcloud/2D/HoughEstimator.h>
#include <libcloud/2D/MeanShiftEstimator.h>
#include <libcloud/2D/ImageDrawer.h>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);
  QImage image (argv[1]);
  Image im;
  im.resize (image.height (), image.width ());
  qDebug ("height: %d width: %d", image.height (), image.width ());
  ImageDrawer drawer (image.height (), image.width ());

  for (UInt32 i = 0; i < image.height (); ++i) {
    for (UInt32 j = 0; j < image.width (); ++j) {
      QRgb c = image.pixel (j, i);
      im.setPixel (i, j, Color (qRed (c), qGreen (c), qBlue (c)));
    }
  }

  Matrix<UInt8> red = im.getYChannel ();
  Matrix<UInt8> edge, ms;
  Matrix<UInt32> param;
  Matrix<UInt32> blurredParam;
  std::vector<Point> modes;

  CannyEstimator canny;

  canny.compute (red, edge);

  HoughEstimator hough;

  hough.setNTheta (400);
  hough.setNRho (400);

  hough.compute (edge, param);

  GaussianEstimator gaussian;
  gaussian.setAperture (9);
  gaussian.setSigma (5.3);

  gaussian.compute (param, blurredParam);
  
  MeanShiftEstimator meanShift;

  meanShift.compute (blurredParam, ms, modes);

  // 45°
  //drawer.drawLine (Line (1, -1, 0), Color (0, 0, 255));
  // 30°
  //drawer.drawLine (Line (0, -M_PI/3), Color (0, 255, 0));
  // 60°
  //drawer.drawLine (Line (0, -M_PI/6), Color (255, 0, 0));

  for (std::vector<Point>::const_reverse_iterator it = modes.rbegin (); it != modes.rend (); ++it) {
    qDebug ("mode: %d %d %d", it->x, it->y, it->z);
    Line line ((it->y-hough.getNRho ()/2)*hough.getRhoStep (edge), -1./2.*M_PI+(it->x*hough.getThetaStep ()));
    drawer.drawLine (line, Color (0, 255, 0));
  }

  ImageViewerWidget viewer0;
  viewer0.setMatrix (&edge);
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

  return app.exec();
}
