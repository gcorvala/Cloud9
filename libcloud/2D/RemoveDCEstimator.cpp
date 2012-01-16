#include "RemoveDCEstimator.h"

RemoveDCEstimator::RemoveDCEstimator ()
{
}

RemoveDCEstimator::~RemoveDCEstimator ()
{
}

void
RemoveDCEstimator::compute (const Matrix<double>& input, Matrix<double>& output) const
{
  UInt32 window_rows;
  UInt32 window_cols;

  if (windowed) {
    window_rows = window_cols = window_aperture*2-1;
  }
  else {
    window_rows = input.getRows ();
    window_cols = input.getCols ();
  }
  Matrix<double> mf (window_rows, window_cols);

  UInt32 window_size_2 = window_rows*window_cols;

  for (UInt32 i = 0; i < window_rows; ++i) {
    for (UInt32 j = 0; j < window_cols; ++j) {
      if (i == window_rows/2 && j == window_cols/2) {
        mf (i, j) = 1.-(1./window_size_2);
      }
      else {
        mf (i, j) = -1./window_size_2;
      }
    }
  }

  input.convolve (mf, output);
}

bool
RemoveDCEstimator::getWindowed () const
{
  return windowed;
}

void
RemoveDCEstimator::setWindowed (bool value)
{
  windowed = value;
}

UInt8
RemoveDCEstimator::getWindowAperture () const
{
  return window_aperture;
}

void
RemoveDCEstimator::setWindowAperture (UInt8 size)
{
  window_aperture = size;
}
