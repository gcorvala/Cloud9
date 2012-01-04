#include "SobelEstimator.h"

SobelEstimator::SobelEstimator ()
{
  x_kernel.resize (3, 3);
  y_kernel.resize (3, 3);

  x_kernel (0, 0) = 1;
  x_kernel (1, 0) = 2;
  x_kernel (2, 0) = 1;
  x_kernel (0, 2) = -1;
  x_kernel (1, 2) = -2;
  x_kernel (2, 2) = -1;

  y_kernel (0, 0) = 1;
  y_kernel (0, 1) = 2;
  y_kernel (0, 2) = 1;
  y_kernel (2, 0) = -1;
  y_kernel (2, 1) = -2;
  y_kernel (2, 2) = -1;
}

SobelEstimator::~SobelEstimator ()
{
}
