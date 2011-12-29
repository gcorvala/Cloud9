#ifndef __ESTIMATOR_H__
#define __ESTIMATOR_H__

#include "Matrix.h"

template <typename InputType, typename OutputType>
class Estimator {
  public:
    Estimator ();
    virtual ~Estimator ();
    void setInputMatrix (const Matrix<InputType>& _matrix);
    virtual void compute (Matrix<OutputType>& output) const = 0;
  protected:
    const Matrix<InputType>* matrix;
};

template <typename InputType, typename OutputType>
Estimator<InputType, OutputType>::Estimator ()
  :matrix(NULL)
{
}

template <typename InputType, typename OutputType>
Estimator<InputType, OutputType>::~Estimator ()
{
}

template <typename InputType, typename OutputType>
void
Estimator<InputType, OutputType>::setInputMatrix (const Matrix<InputType>& _matrix)
{
  if (matrix != &_matrix) {
    matrix = &_matrix;
  }
}
#endif