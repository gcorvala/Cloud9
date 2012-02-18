#ifndef __HOUGH_FILTER_H__
#define __HOUGH_FILTER_H__

#include "../Common/PointCloud.h"

class HoughFilter {
  public:
    HoughFilter ();
    virtual ~HoughFilter ();
    void run (PointCloud& cloud) const;
    void compute (const PointCloud& input, PointCloud& output) const;
};

#endif