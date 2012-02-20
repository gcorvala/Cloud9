#include "HilbertEstimator.h"

HilbertEstimator::HilbertEstimator ()
  :windowed(false)
  ,window_aperture(3)
{
}

HilbertEstimator::~HilbertEstimator ()
{
}

void
HilbertEstimator::compute (const Matrix<Float64>& input, Matrix<Float64>& output) const
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
  Matrix<Float64> mh (window_rows, window_cols);

  Float64 factor = 2./(window_rows*window_cols);

  for (UInt32 i = 0; i < window_rows; ++i) {
    for (UInt32 j = 0; j < window_cols; ++j) {
      mh (i, j) = factor*(1./tan (M_PI/window_cols)*j+1./tan (M_PI/window_rows)*i);
    }
  }

  input.convolve (mh, output);
}

bool
HilbertEstimator::getWindowed () const
{
  return windowed;
}

void
HilbertEstimator::setWindowed (bool value)
{
  windowed = value;
}

UInt8
HilbertEstimator::getWindowAperture () const
{
  return window_aperture;
}

void
HilbertEstimator::setWindowAperture (UInt8 size)
{
  window_aperture = size;
}
