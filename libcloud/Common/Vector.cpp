#include "Vector.h"

#include <math.h>

Vector::Vector (double _x, double _y, double _z)
{
  x = _x;
  y = _y;
  z = _z;
}

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

Vector
Vector::operator- () const
{
  return Vector (-x, -y, -z);
}


Vector
Vector::cross (const Vector& v) const
{
  Vector result;

  result.x = (y*v.z-z*v.y);
  result.y = (z*v.x-x*v.z);
  result.z = (x*v.y-y*v.x);

  return result;
}

double
Vector::dot (const Vector& v) const
{
  double result;

	result = x*v.x + y*v.y + z*v.z;

  return result;
}

double
Vector::angle (const Vector& v) const
{
  Vector a = *this;
  Vector b = v;
  a.normalize ();
  b.normalize ();
  return acos (dot (v));
}