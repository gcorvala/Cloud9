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
  Matrix<double> intensities, angles;
  sobel.compute (tmp, intensities, angles);
  nonMaximaSuppression (intensities, angles);
  output = intensities;
}

void
CannyEstimator::nonMaximaSuppression (Matrix<double>& intensities, const Matrix<double>& angles) const
{
  for (UInt32 i = 1; i < intensities.getRows ()-1; ++i) {
    for (UInt32 j = 1; j < intensities.getCols ()-1; ++j) {
      if (angles (i, j) < M_PI/8 || angles (i, j) >= 7*M_PI/8) {
        if (intensities (i, j) < intensities (i, j-1) || intensities (i, j) < intensities (i, j+1)) {
          intensities (i, j) = 0;
        }
      }
      else if (angles (i, j) >= M_PI/8 && angles (i, j) < 3*M_PI/8) {
        if (intensities (i, j) < intensities (i-1, j+1) || intensities (i, j) < intensities (i+1, j-1)) {
          intensities (i, j) = 0;
        }
      }
      else if (angles (i, j) >= 3*M_PI/8 && angles (i, j) < 5*M_PI/8) {
        if (intensities (i, j) < intensities (i-1, j) || intensities (i, j) < intensities (i+1, j)) {
          intensities (i, j) = 0;
        }
      }
      else if (angles (i, j) >= 5*M_PI/8 && angles (i, j) < 7*M_PI/8) {
        if (intensities (i, j) < intensities (i-1, j-1) || intensities (i, j) < intensities (i+1, j+1)) {
          intensities (i, j) = 0;
        }
      }
    }
  }
}
