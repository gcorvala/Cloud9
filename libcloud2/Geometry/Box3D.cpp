#include "Box3D.h"

Box3D::Box3D (const Point3D& p1, const Point3D& p2)
{
  m_min.x = p1.x < p2.x ? p1.x : p2.x;
  m_min.y = p1.y < p2.y ? p1.y : p2.y;
  m_min.z = p1.z < p2.z ? p1.z : p2.z;
  m_max.x = p1.x > p2.x ? p1.x : p2.x;
  m_max.x = p1.y > p2.y ? p1.y : p2.y;
  m_max.x = p1.z > p2.z ? p1.z : p2.z;
}

Box3D::~Box3D ()
{
}

Point3D
Box3D::getMin () const
{
  return m_min;
}

Point3D
Box3D::getMax () const
{
  return m_max;
}

Float32
Box3D::getDiagonalLength () const
{
  return m_max.distanceTo (m_min);
}