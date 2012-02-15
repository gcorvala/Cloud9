#ifndef __FILTER_H__
#define __FILTER_H__

#include "../Common/PointCloud.h"

class Filter {
  public:
    Filter ();
    virtual ~Filter ();
    virtual void run (PointCloud& cloud) const = 0;
    virtual void compute (const PointCloud& input, PointCloud& output) const = 0;

  protected:
    PointCloud removed;
    double limit_min;
    double limit_max;
};

#endif