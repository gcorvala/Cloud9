#include "CannyEstimator.h"

CannyEstimator::CannyEstimator ()
{
}

CannyEstimator::~CannyEstimator ()
{
}

void
CannyEstimator::compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const
{
  Matrix<UInt8> tmp;
  gaussian.compute (input, tmp);
  Matrix<double> intensities;
  sobel.compute (tmp, intensities);
  output = intensities;
  output = tmp;
}
