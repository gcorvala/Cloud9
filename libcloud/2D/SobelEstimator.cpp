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
SobelEstimator::compute (Matrix<SInt8>& output) const
{
  Matrix<SInt8> sobel_x (3, 3);
  sobel_x(0, 0) = 1;
  sobel_x(0, 2) = -1;
  sobel_x(1, 0) = 2;
  sobel_x(1, 2) = -2;
  sobel_x(2, 0) = 1;
  sobel_x(2, 2) = -1;

  Matrix<SInt8> sobel_y (3, 3);
  sobel_y(0, 0) = 1;
  sobel_y(0, 1) = 2;
  sobel_y(0, 2) = 1;
  sobel_y(2, 0) = -1;
  sobel_y(2, 1) = -2;
  sobel_y(2, 2) = -1;

  output.resize (matrix->getRows ()-2, matrix->getCols ()-2);
  for (unsigned int i = 1; i < matrix->getRows ()-1; ++i) {
    for (unsigned int j = 1; j < matrix->getCols ()-1; ++j) {
      Matrix<SInt8> m = matrix->getSubMatrix (i-1, j-1, 3, 3);
      Matrix<SInt8> x = m.convolve<SInt8> (sobel_x);
      unsigned int gx = x(1,1);
      //float gy = m.convolve (sobel_y)(1,1);
      //unsigned int gx = -m(0,0)+m(0,2)-2*m(1,0)+2*m(1,2)-m(2,0)+m(2,2);
      gx /= 8;
      //unsigned int gy = -m(0,0)-2*m(0,1)-m(0,2)+m(2,0)+2*m(2,1)+m(2,2);
      //gy /= 8;
      //output(i-1,j-1) = sqrt (gx*gx+gy*gy);
      output(i-1,j-1) = gx;
    }
  }
}
