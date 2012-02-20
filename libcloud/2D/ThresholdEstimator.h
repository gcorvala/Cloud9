#ifndef __THRESHOLD_ESTIMATOR_H__
#define __THRESHOLD_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class ThresholdEstimator : public Estimator<Float64, Float64> {
  public:
    ThresholdEstimator ();
    ~ThresholdEstimator ();
    void compute (const Matrix<Float64>& input, Matrix<Float64>& output) const;

    Float64 getThreshold () const;
    void setThreshold (Float64 t);
  protected:
    Float64 threshold;
};

#endif