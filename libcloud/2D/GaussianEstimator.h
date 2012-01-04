#ifndef __GAUSSIAN_ESTIMATOR_H__
#define __GAUSSIAN_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class GaussianEstimator : public Estimator<UInt8, UInt8> {
  public:
    GaussianEstimator ();
    ~GaussianEstimator ();
    void compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const;

    void setAperture (UInt32 _aperture);
    UInt32 getAperture () const;
    void setSigma (double s);
    double getSigma () const;
    Matrix<double> getFilter () const;
  protected:
    void generateFilter ();

    Matrix<double> gaussian_filter;
    UInt32 aperture;
    double sigma;
};

#endif