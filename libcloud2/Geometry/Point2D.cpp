#include "Point2D.h"

#if 0
Point2D::Point2D (Float32 _x, Float32 _y)
  :x(_x)
  ,y(_y)
{
}

Point2D::Point2D (const Point2D& p)
  :x(p.x)
  ,y(p.y)
{
}

Point2D::~Point2D ()
{
}

Float32
Point2D::norm () const
{
  return sqrt (norm2 ());
}

Float32
Point2D::norm2 () const
{
  return x * x + y * y;
}

void
Point2D::normalize ()
{
  *this = normalized ();
}

Point2D
Point2D::normalized () const
{
  return *this / norm ();
}

Boolean
Point2D::operator== (const Point2D& p) const
{
  return (p.x == x && p.y == y);
}

Boolean
Point2D::operator!= (const Point2D& p) const
{
  return !(*this == p);
}

Point2D&
Point2D::operator= (const Point2D& p)
{
  x = p.x;
  y = p.y;
  return *this;
}

Point2D
Point2D::operator+ (const Point2D& p) const
{
  return Point2D (p.x + x, p.y + y);
}

Point2D
Point2D::operator- (const Point2D& p) const
{
  return Point2D (p.x - x, p.y - y);
}

Point2D&
Point2D::operator+= (const Point2D& p)
{
  x += p.x;
  y += p.y;
  return *this;
}

Point2D&
Point2D::operator-= (const Point2D& p)
{
  x -= p.x;
  y -= p.y;
  return *this;
}

Point2D
Point2D::operator* (Float32 s) const
{
  return Point2D (x * s, y * s);
}

Point2D
Point2D::operator/ (Float32 s) const
{
  return Point2D (x / s, y / s);
}

Point2D&
Point2D::operator*= (Float32 s)
{
  x *= s;
  y *= s;
  return *this;
}

Point2D&
Point2D::operator/= (Float32 s)
{
  x /= s;
  y /= s;
  return *this;
}

Float64
Point2D::distanceTo (const Point2D& p) const
{
}

#endif