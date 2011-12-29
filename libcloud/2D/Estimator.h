#ifndef __ESTIMATOR_H__
#define __ESTIMATOR_H__

#include "Matrix.h"

class Estimator {
  public:
    Estimator ();
    virtual ~Estimator ();
    void setInputMatrix (const Matrix<UInt8>& _matrix);
    virtual void compute (Matrix<UInt8>& output) const = 0;
  protected:
    const Matrix<UInt8>* matrix;
};

#endif