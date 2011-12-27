#include <QApplication>
#include <libcloudui/ImageViewer.h>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);
  ImageViewer imageViewer;
  imageViewer.show ();
  return app.exec();
}
