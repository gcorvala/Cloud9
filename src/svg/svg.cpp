#include <libsvg/Document.h>
#include <libsvg/Line.h>
#include <libsvg/Polyline.h>
#include <libsvg/Circle.h>

#include <string>

int
main (int argc, char** argv)
{
  SVG::Document document;
  SVG::Line line (10, 20, 100, 200);
  std::vector < std::pair <Float32, Float32> > points;

  points.push_back (std::make_pair (2000, 1000));
  points.push_back (std::make_pair (100, 1));
  points.push_back (std::make_pair (100, 100));
  points.push_back (std::make_pair (200, 100));
  points.push_back (std::make_pair (200, 200));
  points.push_back (std::make_pair (300, 200));
  points.push_back (std::make_pair (300, 300));

  SVG::Polyline polyline (points);

  SVG::Circle circle (400, 400, 100);

  document.add (line);
  document.add (polyline);
  document.add (circle);

  document.save ("test.svg");

  return 0;
}