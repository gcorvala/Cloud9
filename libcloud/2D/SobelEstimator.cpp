#include "SobelEstimator.h"

#include "../Common/Types.h"
#include <math.h>

SobelEstimator::SobelEstimator ()
{
}

SobelEstimator::~SobelEstimator ()
{
}

void
SobelEstimator::compute (Matrix<UInt8>& output) const
{
  Matrix<SInt8> sobel_x (3, 3);
  sobel_x(0, 0) = 1;
  sobel_x(1, 0) = 2;
  sobel_x(2, 0) = 1;
  sobel_x(0, 2) = -1;
  sobel_x(1, 2) = -2;
  sobel_x(2, 2) = -1;

  Matrix<SInt8> sobel_y (3, 3);
  sobel_y(0, 0) = 1;
  sobel_y(0, 1) = 2;
  sobel_y(0, 2) = 1;
  sobel_y(2, 0) = -1;
  sobel_y(2, 1) = -2;
  sobel_y(2, 2) = -1;

  Matrix<SInt16> gx;
  matrix->convolve (sobel_x, gx);
  Matrix<SInt16> gy;
  matrix->convolve (sobel_y, gy);

  Matrix<SInt32> gx2, gy2;
  gx.mul (gx, gx2);
  gy.mul (gy, gy2);
  //gx2 = gx2.getSubMatrix (1, 1, gx2.getRows ()-2, gx2.getCols ()-2);
  //gy2 = gy2.getSubMatrix (1, 1, gy2.getRows ()-2, gy2.getCols ()-2);

  Matrix<SInt32> r = gx2+gy2;
  Matrix<double> t;
  r.sqrt (t);
  // FIXME : normalize or cut > 255 ? (Gimp normalize)
  //t = (t/t.max ())*255;
  for (UInt32 i = 0; i < t.getRows (); ++i) {
    for (UInt32 j = 0; j < t.getCols (); ++j) {
      if (t(i,j) > 255)
        t(i,j) = 255;
    }
  }
  output = t;
}
