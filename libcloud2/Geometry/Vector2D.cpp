#include "Vector2D.h"

#include <math.h>

Vector2D::Vector2D (Float32 _x, Float32 _y)
  :x(_x)
  ,y(_y)
{
}

Vector2D::Vector2D (const Vector2D& v)
  :x(v.x)
  ,y(v.y)
{
}

Vector2D::~Vector2D ()
{
}

Float32
Vector2D::norm () const
{
  return sqrt (norm2 ());
}

Float32
Vector2D::norm2 () const
{
  return x * x + y * y;
}

void
Vector2D::normalize ()
{
  *this /= norm ();
}

Vector2D
Vector2D::normalized () const
{
  return *this / norm ();
}

Boolean
Vector2D::operator== (const Vector2D& v) const
{
  return v.x == x && v.y == y;
}

Boolean
Vector2D::operator!= (const Vector2D& v) const
{
  return v.x != x || v.y != y;
}

Vector2D&
Vector2D::operator= (const Vector2D& v)
{
  x = v.x;
  y = v.y;
  return *this;
}

Vector2D
Vector2D::operator+ (const Vector2D& v) const
{
  return Vector2D (v.x + x, v.y + y);
}

Vector2D
Vector2D::operator- (const Vector2D& v) const
{
  return Vector2D (v.x - x, v.y - y);
}

Vector2D&
Vector2D::operator+= (const Vector2D& v)
{
  x += v.x;
  y += v.y;
  return *this;
}

Vector2D&
Vector2D::operator-= (const Vector2D& v)
{
  x -= v.x;
  y -= v.y;
  return *this;
}

Vector2D
Vector2D::operator* (Float32 s) const
{
  return Vector2D (x * s, y * s);
}

Vector2D
Vector2D::operator/ (Float32 s) const
{
  return Vector2D (x / s, y / s);
}

Vector2D&
Vector2D::operator*= (Float32 s)
{
  x *= s;
  y *= s;
  return *this;
}

Vector2D&
Vector2D::operator/= (Float32 s)
{
  x /= s;
  y /= s;
  return *this;
}