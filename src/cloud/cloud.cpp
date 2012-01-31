#include <libcloudui/CloudApplication/CloudApplication.h>

int main (int argc, char *argv[])
{
  CloudApplication app (argc, argv);

  return app.exec ();
}