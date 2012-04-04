#include <OdaCommon.h>
#include <Ge/GePlane.h>
#include <iostream>

int
main (int argc, char** argv)
{
  OdGePlane plane;
  OdGePoint3d uPoint(1.0, 1.0, 1.0), origin(0.0, 0.0, 0.0), vPoint(1.0, 1.0, -1.0);
  double a, b, c, d;
  OdGePoint3d point1, point2, point3;

  plane.set(uPoint, origin, vPoint);
  plane.get(point1, point2, point3);
  plane.getCoefficients(a, b, c, d);

  std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;

  return 0;
}