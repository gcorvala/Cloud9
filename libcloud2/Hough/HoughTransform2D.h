#ifndef __HOUGH_TRANSFORM_2D_H__
#define __HOUGH_TRANSFORM_2D_H__

#include "HoughTransform.h"

class HoughTransform2D : public HoughTransform {
  public:
    HoughTransform2D (UInt32 n_rho = 800, UInt32 n_theta = 800);
    ~HoughTransform2D ();

    HoughTransform::ptr copy () const;

    void setInput (const PointCloud3D& cloud);

    void run ();

    UInt32 getNRho () const;
    UInt32 getNTheta () const;

  protected:
    void getInliers (const PointCloud3D& cloud, const Indices& max, Indices& inliers) const;
};

#endif
