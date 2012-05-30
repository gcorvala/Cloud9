#ifndef __HOUGH_TRANSFORM_2D_H__
#define __HOUGH_TRANSFORM_2D_H__

#include "HoughTransform.h"

class HoughTransform2D : public HoughTransform {
  public:
    HoughTransform2D ();
    ~HoughTransform2D ();

    void run ();
};

#endif
