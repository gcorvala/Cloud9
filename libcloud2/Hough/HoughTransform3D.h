#ifndef __HOUGH_TRANSFORM_3D_H__
#define __HOUGH_TRANSFORM_3D_H__

#include "../Common/PointCloud.h"
#include "Accumulator.h"

class HoughTransform3D {
  public:
    HoughTransform3D ();
    ~HoughTransform3D ();

    void setInput (const PointCloud& cloud);
    const PointCloud& getInput () const;

    void run ();

    const Accumulator& getOutput () const;

  protected:
    Accumulator m_accumulator;
    PointCloud::const_ptr m_cloud;
};

#endif
