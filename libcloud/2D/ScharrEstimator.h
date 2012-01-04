#ifndef __SCHARR_ESTIMATOR_H__
#define __SCHARR_ESTIMATOR_H__

#include "GradientEstimator.h"

class ScharrEstimator : public GradientEstimator {
  public:
    ScharrEstimator ();
    ~ScharrEstimator ();
};

#endif