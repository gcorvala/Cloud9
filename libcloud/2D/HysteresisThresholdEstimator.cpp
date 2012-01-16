#include "HysteresisThresholdEstimator.h"

#include "ThresholdEstimator.h"

HysteresisThresholdEstimator::HysteresisThresholdEstimator ()
{
}

HysteresisThresholdEstimator::~HysteresisThresholdEstimator ()
{
}

void
HysteresisThresholdEstimator::compute (const Matrix<double>& input, Matrix<double>& output) const
{
  ThresholdEstimator threshold;
  Matrix<double> high;
  Matrix<double> low;

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

double
HysteresisThresholdEstimator::getLowThreshold () const
{
  return low_threshold;
}

void
HysteresisThresholdEstimator::setLowThreshold (double t)
{
  low_threshold = t;
}

double
HysteresisThresholdEstimator::getHighThreshold () const
{
  return high_threshold;
}

void
HysteresisThresholdEstimator::setHighThreshold (double t)
{
  high_threshold = t;
}
