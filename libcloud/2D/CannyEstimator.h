#ifndef __CANNY_ESTIMATOR_H__
#define __CANNY_ESTIMATOR_H__

#include "Estimator.h"
#include "GaussianEstimator.h"
#include "SobelEstimator.h"
#include "Matrix.h"

class CannyEstimator : public Estimator<UInt8, UInt8> {
  public:
    CannyEstimator ();
    ~CannyEstimator ();

    void compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const;

    Float64 getHighThreshold () const;
    void setHighThreshold (Float64 threshold);
    Float64 getLowThreshold () const;
    void setLowThreshold (Float64 threshold);

  protected:
    void nonMaximaSuppression (Matrix<Float64>& intensities, const Matrix<Float64>& angles) const;

    GaussianEstimator gaussian;
    SobelEstimator sobel;
    Float64 high_threshold;
    Float64 low_threshold;
};

#endif