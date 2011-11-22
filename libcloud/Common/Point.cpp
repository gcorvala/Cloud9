#include "Point.h"

#include <math.h>

Point::Point ()
  : x(0), y(0), z(0)
{
}

Point::Point (double _x, double _y, double _z)
  : x(_x), y(_y), z(_z)
{
}

Point::~Point ()
{
}

void
Point::normalize ()
{
  double size;

  size = norm ();

  x /= size;
  y /= size;
  z /= size;
}

double
Point::norm () const
{
  return sqrt (norm2 ());
}

double
Point::norm2 () const
{
  return x*x + y*y + z*z;
}

Point
Point::operator+ (const Point& p) const
{
  Point q;

  q.x = x + p.x;
  q.y = y + p.y;
  q.z = z + p.z;

  return q;
}

Point
Point::operator- (const Point& p) const
{
  Point q;

  q.x = x - p.x;
  q.y = y - p.y;
  q.z = z - p.z;

  return q;
}

Point
Point::operator* (double s) const
{
  Point q;

  q.x = x*s;
  q.y = y*s;
  q.z = z*s;

  return q;
}

Point
Point::operator/ (double s) const
{
  Point q;

  q.x = x/s;
  q.y = y/s;
  q.z = z/s;

  return q;
}

Point
Point::operator= (const Point& p)
{
  x = p.x;
  y = p.y;
  z = p.z;

  return *this;
}

Point
Point::operator+= (const Point& p)
{
  x += p.x;
  y += p.y;
  z += p.z;

  return *this;
}

Point
Point::operator-= (const Point& p)
{
  x -= p.x;
  y -= p.y;
  z -= p.z;

  return *this;
}

Point
Point::operator*= (double s)
{
  x *= s;
  y *= s;
  z *= s;

  return *this;
}

Point
Point::operator/= (double s)
{
  x /= s;
  y /= s;
  z /= s;

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