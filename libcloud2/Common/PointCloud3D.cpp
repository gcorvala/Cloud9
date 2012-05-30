#include "PointCloud3D.h"

PointCloud3D::PointCloud3D ()
{
}

PointCloud3D::iterator
PointCloud3D::begin ()
{
  return m_points.begin();
}

PointCloud3D::iterator
PointCloud3D::end ()
{
  return m_points.end ();
}

PointCloud3D::const_iterator
PointCloud3D::begin () const
{
  return m_points.begin ();
}

PointCloud3D::const_iterator
PointCloud3D::end () const
{
  return m_points.end ();
}

UInt32
PointCloud3D::size () const
{
  return m_points.size ();
}

void
PointCloud3D::reserve (UInt32 n)
{
  m_points.reserve (n);
}

void
PointCloud3D::resize (UInt32 n)
{
  m_points.resize (n);
}

bool
PointCloud3D::empty ()
{
  return m_points.empty();
}

const Point3D&
PointCloud3D::operator[] (UInt32 n) const
{
  return m_points[n];
}

Point3D&
PointCloud3D::operator[] (UInt32 n)
{
  return m_points[n];
}

const Point3D&
PointCloud3D::at (UInt32 n) const
{
  return m_points.at (n);
}

Point3D&
PointCloud3D::at (UInt32 n)
{
  return m_points.at (n);
}

PointCloud3D&
PointCloud3D::operator+= (const Point3D& p)
{
  m_points.push_back (p);
  return *this;
}

PointCloud3D&
PointCloud3D::operator+= (const PointCloud3D& pc)
{
  const_iterator it;

  for (it = pc.begin (); it != pc.end (); ++it) {
    m_points.push_back (*it);
  }

  return *this;
}

void
PointCloud3D::clear ()
{
  m_points.clear ();
}

BoundingBox3D
PointCloud3D::getBoundingBox () const
{
  BoundingBox3D box;
  const_iterator it;
  
  for (it = m_points.begin (); it != m_points.end (); ++it) {
    box.add (*it);
  }

  return box;
}