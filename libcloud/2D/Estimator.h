#ifndef __ESTIMATOR_H__
#define __ESTIMATOR_H__

#include "Matrix.h"

template <typename InputType, typename OutputType>
class Estimator {
  public:
    Estimator ();
    virtual ~Estimator ();
    virtual void compute (const Matrix<InputType>& input, Matrix<OutputType>& output) const = 0;
};

template <typename InputType, typename OutputType>
Estimator<InputType, OutputType>::Estimator ()
{
}

template <typename InputType, typename OutputType>
Estimator<InputType, OutputType>::~Estimator ()
{
}

#endif