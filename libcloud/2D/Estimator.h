#ifndef __ESTIMATOR_H__
#define __ESTIMATOR_H__

#include "Matrix.h"

class Estimator {
  public:
    Estimator ();
    virtual ~Estimator ();
    void setInputMatrix (const Matrix& _matrix);
    virtual void compute (Matrix& output) const = 0;
  protected:
    const Matrix *matrix;
};

#endif