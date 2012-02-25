#include "Box.h"

#include "Vector.h"

Box::Box (const Point& min, const Point& max)
  :m_min(min)
  ,m_max(max)
{
}

Box::~Box ()
{
}

Point
Box::getMin () const
{
  return m_min;
}

void
Box::setMin (const Point& min)
{
  m_min = min;
}

Point
Box::getMax () const
{
  return m_max;
}

void
Box::setMax (const Point& max)
{
  m_max = max;
}

Point
Box::getCenter () const
{
  return (Vector (m_min)+Vector(m_max))/2;
}

Float64
Box::getWidth () const
{
  return m_max.x-m_min.x;
}

Float64
Box::getHeight () const
{
  return m_max.y-m_min.y;
}

Float64
Box::getDepth () const
{
  return m_max.z-m_min.z;
}