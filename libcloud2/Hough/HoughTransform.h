#ifndef __HOUGH_TRANSFORM_H__
#define __HOUGH_TRANSFORM_H__

#include "../Common/PointCloud3D.h"
#include "Accumulator.h"

class HoughTransform {
  public:
    HoughTransform ();
    ~HoughTransform ();

    void setInput (const PointCloud3D& cloud);
    const PointCloud3D& getInput () const;

    virtual void run () = 0;

    const Accumulator& getAccumulator () const;

  protected:
    Accumulator m_accumulator;
    PointCloud3D::const_ptr m_cloud;
};

#endif
