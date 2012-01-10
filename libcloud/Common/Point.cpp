#include "Point.h"

#include <math.h>

Point::Point (double _x, double _y, double _z)
  : x(_x), y(_y), z(_z)
{
}

Point::~Point ()
{
}

Point
Point::operator= (const Point& p)
{
  x = p.x;
  y = p.y;
  z = p.z;

  return *this;
}

bool
Point::operator== (const Point& p) const
{
  return (x == p.x) && (y == p.y) && (z == p.z);
}

bool
Point::operator!= (const Point& p) const
{
  return (x != p.x) || (y != p.y) || (z != p.z);
}