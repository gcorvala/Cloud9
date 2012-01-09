#ifndef __CROP_BOX_FILTER_H__
#define __CROP_BOX_FILTER_H__

#include "Filter.h"
#include "../Common/Point.h"

class CropBoxFilter : public Filter {
  public:
    CropBoxFilter (const Point& _min, const Point& _max);
    ~CropBoxFilter ();
    void run (PointCloud& cloud) const;
  protected:
    Point min;
    Point max;
};

#endif