#include "BoundingBox3D.h"

#include <limits>

BoundingBox3D::BoundingBox3D ()
{
  m_min.x = std::numeric_limits <Float32>::max ();
  m_min.y = std::numeric_limits <Float32>::max ();
  m_min.z = std::numeric_limits <Float32>::max ();
  m_max.x = std::numeric_limits <Float32>::min ();
  m_max.y = std::numeric_limits <Float32>::min ();
  m_max.z = std::numeric_limits <Float32>::min ();
}

BoundingBox3D::~BoundingBox3D ()
{
}

void
BoundingBox3D::add (const Point3D& p)
{
  m_min.x = p.x < m_min.x ? p.x : m_min.x;
  m_min.y = p.y < m_min.y ? p.y : m_min.y;
  m_min.z = p.z < m_min.z ? p.z : m_min.z;
  m_max.x = p.x > m_max.x ? p.x : m_max.x;
  m_max.y = p.y > m_max.y ? p.y : m_max.y;
  m_max.z = p.z > m_max.z ? p.z : m_max.z;
}