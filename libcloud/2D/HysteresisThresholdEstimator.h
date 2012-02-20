#ifndef __HYSTERESIS_THRESHOLD_ESTIMATOR_H__
#define __HYSTERESIS_THRESHOLD_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class HysteresisThresholdEstimator : public Estimator<Float64, Float64> {
  public:
    HysteresisThresholdEstimator ();
    ~HysteresisThresholdEstimator ();
    void compute (const Matrix<Float64>& input, Matrix<Float64>& output) const;

    Float64 getLowThreshold () const;
    void setLowThreshold (Float64 t);
    Float64 getHighThreshold () const;
    void setHighThreshold (Float64 t);

  protected:
    Float64 low_threshold;
    Float64 high_threshold;
};

#endif