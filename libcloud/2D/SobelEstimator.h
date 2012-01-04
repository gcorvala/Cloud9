#ifndef __SOBEL_ESTIMATOR_H__
#define __SOBEL_ESTIMATOR_H__

#include "GradientEstimator.h"

class SobelEstimator : public GradientEstimator {
  public:
    SobelEstimator ();
    ~SobelEstimator ();
};

#endif