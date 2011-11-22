#include <libcloudui/CloudWindow.h>
#include <QApplication>

int
main (int argc, char** argv)
{
  QApplication app(argc, argv);
  CloudWindow window;
  window.setWindowTitle ("Cloud !!!");
  window.show ();
  return app.exec();
}
