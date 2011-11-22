#include "OctreeLeaf.h"

#include <iostream> // FIXME
#include <string.h>

OctreeLeaf::OctreeLeaf ()
{
}

OctreeLeaf::~OctreeLeaf ()
{
}

OctreeLeafPoint::OctreeLeafPoint ()
{
}

OctreeLeafPoint::~OctreeLeafPoint ()
{
}

void
OctreeLeafPoint::setData (const Point& p)
{
  data = p;
}

void
OctreeLeafPoint::getData (Point& p) const
{
  p = data;
}

void
OctreeLeafPoint::getData (std::vector<Point>& v) const
{
  v.push_back (data);
}

void
OctreeLeafPoint::reset ()
{
  memset (&data, 0, sizeof (data));
}

bool
OctreeLeafPoint::isLeaf () const
{
  return true;
}
