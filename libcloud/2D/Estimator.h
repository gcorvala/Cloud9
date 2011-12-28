#ifndef __ESTIMATOR_H__
#define __ESTIMATOR_H__

#include "Matrix.h"

class Estimator {
  public:
    Estimator ();
    virtual ~Estimator ();
    void setInputMatrix (const Matrix<SInt8>& _matrix);
    virtual void compute (Matrix<SInt8>& output) const = 0;
  protected:
    const Matrix<SInt8>* matrix;
};

#endif