#ifndef __GRADIENT_ESTIMATOR_H__
#define __GRADIENT_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class GradientEstimator : public Estimator<UInt8, Float64> {
  public:
    GradientEstimator ();
    virtual ~GradientEstimator ();
    void compute (const Matrix<UInt8>& input, Matrix<Float64>& output) const;
    void compute (const Matrix<UInt8>& input, Matrix<Float64>& intensities, Matrix<Float64>& angles) const;
  protected:
    Matrix<SInt8> x_kernel;
    Matrix<SInt8> y_kernel;
};

#endif