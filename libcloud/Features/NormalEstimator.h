#ifndef __NORMAL_ESTIMATOR_H__
#define __NORMAL_ESTIMATOR_H__

#include "Feature.h"

class NormalEstimator : public Feature {
  public:
    NormalEstimator ();
    ~NormalEstimator ();
    void compute (PointCloud& output);
  protected:
};

#endif