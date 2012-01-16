#ifndef __HYSTERESIS_THRESHOLD_ESTIMATOR_H__
#define __HYSTERESIS_THRESHOLD_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class HysteresisThresholdEstimator : public Estimator<double, double> {
  public:
    HysteresisThresholdEstimator ();
    ~HysteresisThresholdEstimator ();
    void compute (const Matrix<double>& input, Matrix<double>& output) const;

    double getLowThreshold () const;
    void setLowThreshold (double t);
    double getHighThreshold () const;
    void setHighThreshold (double t);

  protected:
    double low_threshold;
    double high_threshold;
};

#endif