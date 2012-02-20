#include "HysteresisThresholdEstimator.h"

#include "ThresholdEstimator.h"

HysteresisThresholdEstimator::HysteresisThresholdEstimator ()
{
}

HysteresisThresholdEstimator::~HysteresisThresholdEstimator ()
{
}

void
HysteresisThresholdEstimator::compute (const Matrix<Float64>& input, Matrix<Float64>& output) const
{
  ThresholdEstimator threshold;
  Matrix<Float64> high;
  Matrix<Float64> low;

  threshold.setThreshold (high_threshold);

  threshold.compute (input, high);

  threshold.setThreshold (low_threshold);

  threshold.compute (input, low);

  bool modified = true;

  while (modified) {
    modified = false;
    for (UInt32 i = 0; i < high.getRows (); ++i) {
      for (UInt32 j = 0; j < high.getCols (); ++j) {
        if (low (i, j) && !high (i, j)) {
          if (high (i-1, j-1) || high (i-1, j) || high (i-1, j+1)
            || high (i, j-1) || high (i, j) || high (i, j+1)
            || high (i+1, j-1) || high (i+1, j) || high (i+1, j+1)) {
            high (i, j) = 255;
            modified = true;
          }
        }
      }
    }
  }

  output = high;
}

Float64
HysteresisThresholdEstimator::getLowThreshold () const
{
  return low_threshold;
}

void
HysteresisThresholdEstimator::setLowThreshold (Float64 t)
{
  low_threshold = t;
}

Float64
HysteresisThresholdEstimator::getHighThreshold () const
{
  return high_threshold;
}

void
HysteresisThresholdEstimator::setHighThreshold (Float64 t)
{
  high_threshold = t;
}
