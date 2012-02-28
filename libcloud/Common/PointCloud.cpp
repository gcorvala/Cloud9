#include "PointCloud.h"

PointCloud::PointCloud ()
{
}

PointCloud::PointCloud (PointCloud& pc)
{
  *this = pc;
}

PointCloud::PointCloud (const PointCloud& pc)
{
  *this = pc;
}

PointCloud::iterator
PointCloud::begin ()
{
  return points.begin();
}

PointCloud::iterator
PointCloud::end ()
{
  return points.end ();
}

PointCloud::const_iterator
PointCloud::begin () const
{
  return points.begin ();
}

PointCloud::const_iterator
PointCloud::end () const
{
  return points.end ();
}

UInt32
PointCloud::size () const
{
  return points.size ();
}

void
PointCloud::reserve (UInt32 n)
{
  points.reserve (n);
}

void
PointCloud::resize (UInt32 n)
{
  points.resize (n);
}

bool
PointCloud::empty ()
{
  return points.empty();
}

const Point&
PointCloud::operator[] (UInt32 n) const
{
  return points[n];
}

Point&
PointCloud::operator[] (UInt32 n)
{
  return points[n];
}

const Point&
PointCloud::at (UInt32 n) const
{
  return points.at (n);
}

Point&
PointCloud::at (UInt32 n)
{
  return points.at (n);
}

const Point&
PointCloud::front () const
{
  return points.front();
}

Point&
PointCloud::front ()
{
  return points.front();
}

const Point&
PointCloud::back () const
{
  return points.back();
}

Point&
PointCloud::back ()
{
  return points.back();
}

void
PointCloud::push_back (const Point& p)
{
  points.push_back (p);
}

PointCloud::iterator
PointCloud::insert (iterator position, const Point& p)
{
  return points.insert (position, p);
}

void
PointCloud::insert (iterator position, UInt32 n, const Point& p)
{
  points.insert (position, n, p);
}

PointCloud::iterator
PointCloud::erase (iterator position)
{
  return points.erase (position);
}

PointCloud::iterator
PointCloud::erase (iterator first, iterator last)
{
  return points.erase (first, last);
}

void
PointCloud::clear ()
{
  points.clear ();
}

#include <cfloat>

Point
PointCloud::getMin () const
{
  Point min (FLT_MAX, FLT_MAX, FLT_MAX);

  for (PointCloud::const_iterator it = begin (); it != end (); ++it) {
    Point p = *it;
    if (p.x < min.x) min.x = p.x;
    if (p.y < min.y) min.y = p.y;
    if (p.z < min.z) min.z = p.z;
  }

  return min;
}

Point
PointCloud::getMax () const
{
  Point max (-FLT_MAX, -FLT_MAX, -FLT_MAX);

  for (PointCloud::const_iterator it = begin (); it != end (); ++it) {
    Point p = *it;
    if (p.x > max.x) max.x = p.x;
    if (p.y > max.y) max.y = p.y;
    if (p.z > max.z) max.z = p.z;
  }

  return max;
}

Box
PointCloud::getBoundingBox () const
{
  return Box (getMin (), getMax ());
}