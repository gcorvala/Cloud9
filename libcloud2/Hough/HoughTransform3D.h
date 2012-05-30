#ifndef __HOUGH_TRANSFORM_3D_H__
#define __HOUGH_TRANSFORM_3D_H__

#include "HoughTransform.h"

class HoughTransform3D : public HoughTransform {
  public:
    HoughTransform3D ();
    ~HoughTransform3D ();

    void run ();
};

#endif
