#include "SobelEstimator.h"

#include <math.h>

SobelEstimator::SobelEstimator ()
{
}

SobelEstimator::~SobelEstimator ()
{
}

void
SobelEstimator::compute (Matrix& output) const
{
  output.resize (matrix->getRows ()-2, matrix->getCols ()-2);
  for (unsigned int i = 1; i < matrix->getRows ()-1; ++i) {
    for (unsigned int j = 1; j < matrix->getCols ()-1; ++j) {
      Matrix m = matrix->getSubMatrix (i-1, j-1, 3, 3);
      unsigned int gx = -1*m(0,0).getY()+m(0,2).getY()-2*m(1,0).getY()+2*m(1,2).getY()-1*m(2,0).getY()+m(2,2).getY();
      unsigned int gy = -1*m(0,0).getY()-2*m(0,1).getY()-1*m(0,2).getY()+m(2,0).getY()+2*m(2,1).getY()+m(2,2).getY();
      unsigned int g = sqrt (gx*gx+gy*gy);
      output(i-1,j-1) = Color (g, g, g);
    }
  }
}
