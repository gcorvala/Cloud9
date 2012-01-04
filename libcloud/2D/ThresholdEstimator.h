#ifndef __THRESHOLD_ESTIMATOR_H__
#define __THRESHOLD_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class ThresholdEstimator : public Estimator<UInt8, UInt8> {
  public:
    ThresholdEstimator ();
    ~ThresholdEstimator ();
    void compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const;

    UInt8 getThreshold () const;
    void setThreshold (UInt8 t);
  protected:
    UInt8 threshold;
};

#endif