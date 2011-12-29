#ifndef __SOBEL_ESTIMATOR_H__
#define __SOBEL_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class SobelEstimator : public Estimator {
  public:
    SobelEstimator ();
    ~SobelEstimator ();
    void compute (Matrix<UInt8>& output) const;
  protected:
};

#endif