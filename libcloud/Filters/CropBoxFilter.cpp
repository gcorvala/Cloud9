#include "CropBoxFilter.h"

#include "../Common/Types.h"

CropBoxFilter::CropBoxFilter (const Point& _min, const Point& _max)
  :min(_min)
  ,max(_max)
{
}

CropBoxFilter::~CropBoxFilter ()
{
}

void
CropBoxFilter::run (PointCloud& cloud) const
{
  PointCloud result;

  for (PointCloud::const_iterator it = cloud.begin (); it != cloud.end (); ++it) {
    Point p = *it;
    if (p.x >= min.x && p.x <= max.x &&
        p.y >= min.y && p.y <= max.y &&
        p.z >= min.z && p.z <= max.z) {
      result.push_back (p);
    }
  }

  cloud = result;
}

void
CropBoxFilter::compute (const PointCloud& input, PointCloud& output) const
{
  output.clear ();

  for (PointCloud::const_iterator it = input.begin (); it != input.end (); ++it) {
    Point p = *it;
    if (p.x >= min.x && p.x <= max.x &&
        p.y >= min.y && p.y <= max.y &&
        p.z >= min.z && p.z <= max.z) {
      output.push_back (p);
    }
  }
}

void
CropBoxFilter::setMin (const Point& _min)
{
  min = _min;
}

Point
CropBoxFilter::getMin () const
{
  return min;
}

void
CropBoxFilter::setMax (const Point& _max)
{
  max = _max;
}

Point
CropBoxFilter::getMax () const
{
  return max;
}
