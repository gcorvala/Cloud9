#ifndef __FOURIER_ESTIMATOR_H__
#define __FOURIER_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include <complex>

class FourierEstimator : public Estimator<Float64, std::complex<Float64> > {
  public:
    FourierEstimator ();
    ~FourierEstimator ();
    void compute (const Matrix<Float64>& input, Matrix<std::complex<Float64> >& output) const;
};

#endif