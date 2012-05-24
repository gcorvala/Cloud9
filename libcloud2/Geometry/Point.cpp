#include "Point.h"

#include <math.h>

Point::Point (Float32 _x, Float32 _y, Float32 _z)
  :x (_x)
  ,y (_y)
  ,z (_z)
{
}

Point::~Point ()
{
}

Float64
Point::distanceTo (const Point& p) const
{
  Float64 dx = x - p.x;
  Float64 dy = y - p.y;
  Float64 dz = z - p.z;
  return sqrt (dx * dx + dy * dy + dz * dz);
}


Point&
Point::operator= (const Point& p)
{
  x = p.x;
  y = p.y;
  return *this;
}