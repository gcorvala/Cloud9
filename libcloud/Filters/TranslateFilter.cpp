#include "TranslateFilter.h"

#include "../Common/Vector.h"

TranslateFilter::TranslateFilter (double x, double y, double z)
  : direction(x,y,z)
{
}

TranslateFilter::TranslateFilter (Point& p)
  : direction(p)
{
}

TranslateFilter::~TranslateFilter ()
{
}

void
TranslateFilter::run (PointCloud& cloud) const {
  PointCloud::iterator it;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    Vector v (*it);
    v += direction;
    *it = v;
  }
}
