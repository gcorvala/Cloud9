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
HilbertEstimator::compute (const Matrix<double>& input, Matrix<double>& output) const
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
  Matrix<double> mh (window_rows, window_cols);

  double factor = 2./(window_rows*window_cols);

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
