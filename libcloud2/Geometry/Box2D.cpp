#include "Box2D.h"

Box2D::Box2D (const Point2D& p1, const Point2D& p2)
{
  m_min.x = p1.x < p2.x ? p1.x : p2.x;
  m_min.y = p1.y < p2.y ? p1.y : p2.y;
  m_max.x = p1.x > p2.x ? p1.x : p2.x;
  m_max.y = p1.y > p2.y ? p1.y : p2.y;
}

Box2D::~Box2D ()
{
}

Point2D
Box2D::getMin () const
{
  return m_min;
}

Point2D
Box2D::getMax () const
{
  return m_max;
}