#include "ScharrEstimator.h"

ScharrEstimator::ScharrEstimator ()
{
  x_kernel.resize (3, 3);
  y_kernel.resize (3, 3);

  x_kernel (0, 0) = 3;
  x_kernel (1, 0) = 10;
  x_kernel (2, 0) = 3;
  x_kernel (0, 2) = -3;
  x_kernel (1, 2) = -10;
  x_kernel (2, 2) = -3;

  y_kernel (0, 0) = 3;
  y_kernel (0, 1) = 10;
  y_kernel (0, 2) = 3;
  y_kernel (2, 0) = -3;
  y_kernel (2, 1) = -10;
  y_kernel (2, 2) = -3;
}

ScharrEstimator::~ScharrEstimator ()
{
}
