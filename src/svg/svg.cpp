#include <libsvg/Document.h>
#include <libsvg/Line.h>

#include <string>

int
main (int argc, char** argv)
{
  SVG::Document document;
  SVG::Line line (Point2D <Float32> (10, 10), Point2D <Float32> (500, 500));

  document.add (line);
  document.save ("test.svg");

  return 0;
}