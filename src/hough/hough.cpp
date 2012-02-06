#include <QApplication>

#include <libcloudui/Viewers/ImageViewerWidget.h>

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

  ImageViewerWidget viewer;
  viewer.setImage (&im);
  viewer.show ();
  return app.exec();
}
