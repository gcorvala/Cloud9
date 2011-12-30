#include "ThresholdEstimator.h"

ThresholdEstimator::ThresholdEstimator ()
  :threshold(128)
{
}

ThresholdEstimator::~ThresholdEstimator ()
{
}

void
ThresholdEstimator::compute (Matrix<UInt8>& output) const
{
  output.resize (matrix->getRows (), matrix->getCols ());

  for (UInt32 i = 0; i < matrix->getRows (); ++i) {
    for (UInt32 j = 0; j < matrix->getCols (); ++j) {
      if (matrix->at(i,j) >= threshold) {
        output(i,j) = 255;
      }
      else {
        output(i,j) = 0;
      }
    }
  }
}

UInt8
ThresholdEstimator::getThreshold () const
{
  return threshold;
}

void
ThresholdEstimator::setThreshold (UInt8 t)
{
  threshold = t;
}
