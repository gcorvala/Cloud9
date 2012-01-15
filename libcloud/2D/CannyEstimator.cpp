#include "CannyEstimator.h"

#include "ThresholdEstimator.h"

CannyEstimator::CannyEstimator ()
  :high_threshold(100)
  ,low_threshold(5)
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
  Matrix<double> intensities, angles;
  sobel.compute (tmp, intensities, angles);
  nonMaximaSuppression (intensities, angles);
  hysteresisThresholding (intensities);
  output = intensities;
}

double
CannyEstimator::getHighThreshold () const
{
  return high_threshold;
}

void
CannyEstimator::setHighThreshold (double threshold)
{
  high_threshold = threshold;
}

double
CannyEstimator::getLowThreshold () const
{
  return low_threshold;
}

void
CannyEstimator::setLowThreshold (double threshold)
{
  low_threshold = threshold;
}

void
CannyEstimator::nonMaximaSuppression (Matrix<double>& intensities, const Matrix<double>& angles) const
{
  Matrix<double> tmp;
  tmp = intensities;
  for (UInt32 i = 1; i < intensities.getRows ()-1; ++i) {
    for (UInt32 j = 1; j < intensities.getCols ()-1; ++j) {
      if (angles (i, j) < M_PI/8 || angles (i, j) >= 7*M_PI/8) {
        if (intensities (i, j) < intensities (i, j-1) || intensities (i, j) < intensities (i, j+1)) {
          tmp (i, j) = 0;
        }
      }
      else if (angles (i, j) >= M_PI/8 && angles (i, j) < 3*M_PI/8) {
        if (intensities (i, j) < intensities (i-1, j+1) || intensities (i, j) < intensities (i+1, j-1)) {
          tmp (i, j) = 0;
        }
      }
      else if (angles (i, j) >= 3*M_PI/8 && angles (i, j) < 5*M_PI/8) {
        if (intensities (i, j) < intensities (i-1, j) || intensities (i, j) < intensities (i+1, j)) {
          tmp (i, j) = 0;
        }
      }
      else if (angles (i, j) >= 5*M_PI/8 && angles (i, j) < 7*M_PI/8) {
        if (intensities (i, j) < intensities (i-1, j-1) || intensities (i, j) < intensities (i+1, j+1)) {
          tmp (i, j) = 0;
        }
      }
    }
  }

  intensities = tmp;
}

void
CannyEstimator::hysteresisThresholding (Matrix<double>& intensities) const
{
  ThresholdEstimator threshold;
  Matrix<double> high;
  Matrix<double> low;

  threshold.setThreshold (high_threshold);

  threshold.compute (intensities, high);

  threshold.setThreshold (low_threshold);

  threshold.compute (intensities, low);

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

  intensities = high;
}