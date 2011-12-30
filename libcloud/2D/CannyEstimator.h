#ifndef __CANNY_ESTIMATOR_H__
#define __CANNY_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class CannyEstimator : public Estimator<UInt8, UInt8> {
  public:
    CannyEstimator ();
    ~CannyEstimator ();
    void compute (Matrix<UInt8>& output) const;
  protected:
};

#endif