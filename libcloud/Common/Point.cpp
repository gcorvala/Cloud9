#include "Point.h"

#include <math.h>

Point::Point (Float64 _x, Float64 _y, Float64 _z, const Color& color)
  :x(_x)
  ,y(_y)
  ,z(_z)
  ,m_color(color)
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

Float64
Point::distanceTo (const Point& p) const
{
  Float64 dx = p.x-x;
  Float64 dy = p.y-y;
  Float64 dz = p.z-z;
  return sqrt (dx*dx+dy*dy+dz*dz);
}

std::ostream&
operator<< (std::ostream& out, const Point& p)
{
  out << "Point: (" << p.x << "," << p.y << "," << p.z << ")";
}