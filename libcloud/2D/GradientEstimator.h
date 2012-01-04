#ifndef __GRADIENT_ESTIMATOR_H__
#define __GRADIENT_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class GradientEstimator : public Estimator<UInt8, double> {
  public:
    GradientEstimator ();
    virtual ~GradientEstimator ();
    void compute (const Matrix<UInt8>& input, Matrix<double>& output) const;
    void compute (const Matrix<UInt8>& input, Matrix<double>& intensities, Matrix<double>& angles) const;
  protected:
    Matrix<SInt8> x_kernel;
    Matrix<SInt8> y_kernel;
};

#endif