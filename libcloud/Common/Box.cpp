#include "Box.h"

#include "Vector.h"

Box::Box (const Point& min, const Point& max)
{
  if (min.x < max.x) {
    m_min.x = min.x;
    m_max.x = max.x;
  }
  else {
    m_min.x = max.x;
    m_max.x = min.x;
  }

  if (min.y < max.y) {
    m_min.y = min.y;
    m_max.y = max.y;
  }
  else {
    m_min.y = max.y;
    m_max.y = min.y;
  }

  if (min.z < max.z) {
    m_min.z = min.z;
    m_max.z = max.z;
  }
  else {
    m_min.z = max.z;
    m_max.z = min.z;
  }
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