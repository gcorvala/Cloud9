#include "Estimator.h"

Estimator::Estimator ()
  :matrix(NULL)
{
}

Estimator::~Estimator ()
{
}

void
Estimator::setInputMatrix (const Matrix<SInt8>& _matrix)
{
  if (matrix != &_matrix) {
    matrix = &_matrix;
  }
}