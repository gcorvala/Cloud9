#ifndef __CROP_BOX_FILTER_H__
#define __CROP_BOX_FILTER_H__

#include "Filter.h"
#include "../Common/Point.h"

class CropBoxFilter : public Filter {
  public:
    CropBoxFilter (const Point& _min = Point (0, 0, 0), const Point& _max = Point (1, 1, 1));
    ~CropBoxFilter ();
    void run (PointCloud& cloud) const;
    void compute (const PointCloud& input, PointCloud& output) const;

    void setMin (const Point& _min);
    Point getMin () const;
    void setMax (const Point& _max);
    Point getMax () const;

  protected:
    Point min;
    Point max;
};

#endif