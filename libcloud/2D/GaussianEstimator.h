#ifndef __GAUSSIAN_ESTIMATOR_H__
#define __GAUSSIAN_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class GaussianEstimator : public Estimator<UInt32, UInt32> {
  public:
    GaussianEstimator ();
    ~GaussianEstimator ();
    void compute (const Matrix<UInt32>& input, Matrix<UInt32>& output) const;

    void setAperture (UInt32 _aperture);
    UInt32 getAperture () const;
    void setSigma (Float64 s);
    Float64 getSigma () const;
    Matrix<Float64> getFilter () const;
  protected:
    void generateFilter ();

    Matrix<Float64> gaussian_filter;
    UInt32 aperture;
    Float64 sigma;
};

#endif