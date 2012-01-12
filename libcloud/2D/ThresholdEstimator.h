#ifndef __THRESHOLD_ESTIMATOR_H__
#define __THRESHOLD_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class ThresholdEstimator : public Estimator<double, double> {
  public:
    ThresholdEstimator ();
    ~ThresholdEstimator ();
    void compute (const Matrix<double>& input, Matrix<double>& output) const;

    double getThreshold () const;
    void setThreshold (double t);
  protected:
    double threshold;
};

#endif