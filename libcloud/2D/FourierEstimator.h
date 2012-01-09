#ifndef __FOURIER_ESTIMATOR_H__
#define __FOURIER_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include <complex>

class FourierEstimator : public Estimator<double, std::complex<double> > {
  public:
    FourierEstimator ();
    ~FourierEstimator ();
    void compute (const Matrix<double>& input, Matrix<std::complex<double> >& output) const;
};

#endif