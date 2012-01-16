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

    double getHighThreshold () const;
    void setHighThreshold (double threshold);
    double getLowThreshold () const;
    void setLowThreshold (double threshold);

  protected:
    void nonMaximaSuppression (Matrix<double>& intensities, const Matrix<double>& angles) const;

    GaussianEstimator gaussian;
    SobelEstimator sobel;
    double high_threshold;
    double low_threshold;
};

#endif