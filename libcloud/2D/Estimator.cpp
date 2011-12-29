#include "Estimator.h"

Estimator::Estimator ()
  :matrix(NULL)
{
}

Estimator::~Estimator ()
{
}

void
Estimator::setInputMatrix (const Matrix<UInt8>& _matrix)
{
  if (matrix != &_matrix) {
    matrix = &_matrix;
  }
}