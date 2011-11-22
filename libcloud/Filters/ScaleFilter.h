#ifndef __SCALE_FILTER_H__
#define __SCALE_FILTER_H__

#include "Filter.h"

class ScaleFilter : public Filter {
  public:
    ScaleFilter (double _factor);
    ~ScaleFilter ();
    void run (PointCloud& cloud) const;
  protected:
    double factor;
};

#endif