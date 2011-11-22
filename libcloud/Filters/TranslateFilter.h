#ifndef __TRANSLATE_FILTER_H__
#define __TRANSLATE_FILTER_H__

#include "Filter.h"
#include "../Common/Point.h"
#include "../Common/PointCloud.h"

class TranslateFilter : public Filter {
  public:
    TranslateFilter (double x, double y, double z);
    TranslateFilter (Point& p);
    ~TranslateFilter ();
    void run (PointCloud& cloud) const;
  protected:
    Point direction;
};

#endif