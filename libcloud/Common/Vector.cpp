#include "Vector.h"

#include <math.h>

Vector::Vector (const Point& p1, const Point& p2)
{
  x = p2.x-p1.x;
  y = p2.y-p1.y;
  z = p2.z-p1.z;
}

void
Vector::normalize ()
{
  double size;

  size = norm ();

  x /= size;
  y /= size;
  z /= size;
}

double
Vector::norm () const
{
  return sqrt (norm2 ());
}

double
Vector::norm2 () const
{
  return x*x + y*y + z*z;
}

Vector
Vector::operator+ (const Vector& v) const
{
  Vector w;

  w.x = x + v.x;
  w.y = y + v.y;
  w.z = z + v.z;

  return w;
}

Vector
Vector::operator- (const Vector& v) const
{
  Vector w;

  w.x = x - v.x;
  w.y = y - v.y;
  w.z = z - v.z;

  return w;
}

Vector
Vector::operator* (double s) const
{
  Vector v;

  v.x = x*s;
  v.y = y*s;
  v.z = z*s;

  return v;
}

Vector
Vector::operator/ (double s) const
{
  Vector v;

  v.x = x/s;
  v.y = y/s;
  v.z = z/s;

  return v;
}

Vector
Vector::operator+= (const Vector& v)
{
  x += v.x;
  y += v.y;
  z += v.z;

  return *this;
}

Vector
Vector::operator-= (const Vector& v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;

  return *this;
}

Vector
Vector::operator*= (double s)
{
  x *= s;
  y *= s;
  z *= s;

  return *this;
}

Vector
Vector::operator/= (double s)
{
  x /= s;
  y /= s;
  z /= s;

  return *this;
}