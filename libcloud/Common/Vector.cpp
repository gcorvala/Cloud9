#include "Vector.h"

#include <math.h>

Vector::Vector (Float64 _x, Float64 _y, Float64 _z)
{
  x = _x;
  y = _y;
  z = _z;
}

Vector::Vector (const Point& p1, const Point& p2)
{
  x = p1.x-p2.x;
  y = p1.y-p2.y;
  z = p1.z-p2.z;
}

void
Vector::normalize ()
{
  Float64 size;

  size = norm ();

  x /= size;
  y /= size;
  z /= size;
}

Vector
Vector::normalized () const
{
  Float64 size;

  size = norm ();

  return Vector (x/size, y/size, z/size);
}

Float64
Vector::norm () const
{
  return sqrt (norm2 ());
}

Float64
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
Vector::operator* (Float64 s) const
{
  Vector v;

  v.x = x*s;
  v.y = y*s;
  v.z = z*s;

  return v;
}

Vector
Vector::operator/ (Float64 s) const
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
Vector::operator*= (Float64 s)
{
  x *= s;
  y *= s;
  z *= s;

  return *this;
}

Vector
Vector::operator/= (Float64 s)
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

Float64
Vector::dot (const Vector& v) const
{
  Float64 result;

	result = x*v.x + y*v.y + z*v.z;

  return result;
}

Float64
Vector::angle (const Vector& v) const
{
  Vector a = *this;
  Vector b = v;
  a.normalize ();
  b.normalize ();
  return acos (dot (v));
}