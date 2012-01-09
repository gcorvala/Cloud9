#include "CropBoxFilter.h"

CropBoxFilter::CropBoxFilter (const Point& _min, const Point& _max)
{
  min = _min;
  max = _max;
}

CropBoxFilter::~CropBoxFilter ()
{
}

void
CropBoxFilter::run (PointCloud& cloud) const
{
  PointCloud::iterator it;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    Point &p = *it;
    if (p.x < min.x || p.y < min.y || p.z < min.z) {
      it = cloud.erase (it);
      --it;
    }
    else if (p.x > max.x || p.y > max.y || p.z > max.z) {
      it = cloud.erase (it);
      --it;
    }
  }
}
