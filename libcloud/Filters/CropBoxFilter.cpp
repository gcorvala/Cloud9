#include "CropBoxFilter.h"

#include "../Common/Types.h"
#include <iostream>

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

  for (UInt32 i = 0; i < cloud.size (); ++i) {
    Point& p = cloud[i];
    if (p.x < min.x || p.y < min.y || p.z < min.z) {
      it = cloud.erase (cloud.begin ()+i);
    }
    else if (p.x > max.x || p.y > max.y || p.z > max.z) {
      it = cloud.erase (cloud.begin ()+i);
    }
    std::cout << i << std::endl;
  }
  /*for (it = cloud.begin (); it != cloud.end (); ++it) {
    Point &p = *it;
    if (p.x < min.x || p.y < min.y || p.z < min.z) {
      it = cloud.erase (it);
      --it;
    }
    else if (p.x > max.x || p.y > max.y || p.z > max.z) {
      it = cloud.erase (it);
      --it;
    }
    std::cout << std::distance (cloud.begin (), it) << std::endl;
  }*/
}
