#include "GradientEstimator.h"

GradientEstimator::GradientEstimator ()
{
}

GradientEstimator::~GradientEstimator ()
{
  
}

void
GradientEstimator::compute (const Matrix<UInt8>& input, Matrix<double>& output) const
{
  Matrix<double> tmp;

  compute (input, output, tmp);
}

void
GradientEstimator::compute (const Matrix<UInt8>& input, Matrix<double>& intensities, Matrix<double>& angles) const
{
  Matrix<SInt16> gx;
  Matrix<SInt16> gy;
  Matrix<SInt32> gx2, gy2;
  Matrix<SInt32> sum;
  Matrix<double> root;

  input.convolve (x_kernel, gx);
  input.convolve (y_kernel, gy);

  gx.mul (gx, gx2);
  gy.mul (gy, gy2);

  sum = gx2+gy2;
  sum.sqrt (root);

  // FIXME : normalize or cut > 255 ? (Gimp normalize)
  //t = (t/t.max ())*255;
  for (UInt32 i = 0; i < root.getRows (); ++i) {
    for (UInt32 j = 0; j < root.getCols (); ++j) {
      if (root(i,j) > 255)
        root(i,j) = 255;
    }
  }

  intensities = root;

  angles.resize (input.getRows (), input.getCols ());

  for (UInt32 i = 0; i < angles.getRows (); ++i) {
    for (UInt32 j = 0; j < angles.getCols (); ++j) {
      angles (i, j) = atan2 (gy (i, j), gx (i, j));
    }
  }

}
