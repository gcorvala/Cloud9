#include "ScaleFilter.h"

#include "../Common/Vector.h"

ScaleFilter::ScaleFilter (double _factor)
  : factor(_factor)
{
}

ScaleFilter::~ScaleFilter ()
{
}

void
ScaleFilter::run (PointCloud& cloud) const
{
  PointCloud::iterator it;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    Vector v (*it);
    v *= factor;
    *it = v;
  }
}
