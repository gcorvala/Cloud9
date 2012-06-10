#include "Line2D.h"

#include <math.h>
#include <limits>
#include <iostream>

Line2D::Line2D ()
  :m_a (1)
  ,m_b (0)
  ,m_c (0)
{
}

Line2D::Line2D (Float32 rho, Float32 theta)
  :m_a (cos (theta))
  ,m_b (sin (theta))
  ,m_c (-rho)
{
  DEBUG ("");
}

Line2D::Line2D (Float32 a, Float32 b, Float32 c)
  :m_a (a)
  ,m_b (b)
  ,m_c (c)
{
}

Line2D::Line2D (const Point2D& p1, const Point2D& p2)
  :m_a (p1.y - p2.y)
  ,m_b (p1.x - p2.x)
  ,m_c (-m_a * p1.x - m_b * p1.y)
{
}

Line2D::~Line2D ()
{
}

Float32
Line2D::getSlope () const
{
  Float32 slope;

  slope = -m_a / m_b;

  return slope;
}

Float32
Line2D::getYIntercept () const
{
  return -m_c / m_b;
}

Float32
Line2D::getXIntercept () const
{
  return -m_c / m_a;
}

Float32
Line2D::getRho () const
{
  return -m_c;
}

Float32
Line2D::getTheta () const
{
  Float32 theta;

  theta = atan2 (m_b, m_a);
  if (theta < 0) {
    theta += M_PI * 2;
  }

  return theta;
}

Float32
Line2D::getXValue (Float32 y) const
{
  return -(m_b * y + m_c) / m_a;
}

Float32
Line2D::getYValue (Float32 x) const
{
  return -(m_a * x + m_c) / m_b;
}

void
Line2D::translate (const Vector2D& v)
{
  m_c += m_a * v.x + m_b * v.y;
}

Point2D
Line2D::getIntersection (const Line2D& Line2D) const
{
  Float32 delta = m_a * Line2D.m_b - Line2D.m_a * m_b;

  return Point2D (-(Line2D.m_b * m_c - m_b * Line2D.m_c) / delta, -(m_a * Line2D.m_c - Line2D.m_a * m_c) / delta);
}

Line2D
Line2D::getPerpendicular (const Point2D& p) const
{
  return Line2D (-m_b, m_a, m_b * p.x - m_a * p.y);
}

Float32
Line2D::valueAt (const Point2D& p) const
{
  return m_a * p.x + m_b * p.y + m_c;
}