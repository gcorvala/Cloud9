#if 0
#include "ThresholdEstimator.h"

ThresholdEstimator::ThresholdEstimator ()
  :threshold(128)
{
}

ThresholdEstimator::~ThresholdEstimator ()
{
}

void
ThresholdEstimator::compute (const Matrix<Float64>& input, Matrix<Float64>& output) const
{
  output.resize (input.getRows (), input.getCols ());

  for (UInt32 i = 0; i < input.getRows (); ++i) {
    for (UInt32 j = 0; j < input.getCols (); ++j) {
      if (input(i,j) >= threshold) {
        output(i,j) = 255;
      }
      else {
        output(i,j) = 0;
      }
    }
  }
}

Float64
ThresholdEstimator::getThreshold () const
{
  return threshold;
}

void
ThresholdEstimator::setThreshold (Float64 t)
{
  threshold = t;
}
#endif