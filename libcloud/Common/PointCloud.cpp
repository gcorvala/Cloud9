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

size_t
PointCloud::size () const
{
  return points.size ();
}

void
PointCloud::reserve (size_t n)
{
  points.reserve (n);
}

void
PointCloud::resize (size_t n)
{
  points.resize (n);
}

bool
PointCloud::empty ()
{
  return points.empty();
}

const Point&
PointCloud::operator[] (size_t n) const
{
  return points[n];
}

Point&
PointCloud::operator[] (size_t n)
{
  return points[n];
}

const Point&
PointCloud::at (size_t n) const
{
  return points.at (n);
}

Point&
PointCloud::at (size_t n)
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
PointCloud::insert (iterator position, size_t n, const Point& p)
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
