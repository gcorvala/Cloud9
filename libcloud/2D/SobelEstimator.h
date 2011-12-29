#ifndef __SOBEL_ESTIMATOR_H__
#define __SOBEL_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class SobelEstimator : public Estimator<UInt8, UInt8> {
  public:
    SobelEstimator ();
    ~SobelEstimator ();
    void compute (Matrix<UInt8>& output) const;
  protected:
};

#endif