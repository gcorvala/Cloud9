#include "PointCloud.h"

PointCloud::PointCloud ()
{
}

PointCloud::iterator
PointCloud::begin ()
{
  return m_points.begin();
}

PointCloud::iterator
PointCloud::end ()
{
  return m_points.end ();
}

PointCloud::const_iterator
PointCloud::begin () const
{
  return m_points.begin ();
}

PointCloud::const_iterator
PointCloud::end () const
{
  return m_points.end ();
}

UInt32
PointCloud::size () const
{
  return m_points.size ();
}

void
PointCloud::reserve (UInt32 n)
{
  m_points.reserve (n);
}

void
PointCloud::resize (UInt32 n)
{
  m_points.resize (n);
}

bool
PointCloud::empty ()
{
  return m_points.empty();
}

const Point&
PointCloud::operator[] (UInt32 n) const
{
  return m_points[n];
}

Point&
PointCloud::operator[] (UInt32 n)
{
  return m_points[n];
}

const Point&
PointCloud::at (UInt32 n) const
{
  return m_points.at (n);
}

Point&
PointCloud::at (UInt32 n)
{
  return m_points.at (n);
}

PointCloud&
PointCloud::operator+= (const Point& p)
{
  m_points.push_back (p);
  return *this;
}

PointCloud&
PointCloud::operator+= (const PointCloud& pc)
{
  const_iterator it;

  for (it = pc.begin (); it != pc.end (); ++it) {
    m_points.push_back (*it);
  }

  return *this;
}


void
PointCloud::clear ()
{
  m_points.clear ();
}