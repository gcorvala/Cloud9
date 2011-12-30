#ifndef __HOUGH_ESTIMATOR_H__
#define __HOUGH_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include "Line.h"

class HoughEstimator : public Estimator<UInt8, UInt8> {
  public:
    HoughEstimator ();
    ~HoughEstimator ();
    void compute (Matrix<UInt8>& output) const;
    void setInputMatrix (const Matrix<UInt8>& _matrix);

    void getLines (Matrix<UInt8>& hough, std::vector<Line>& lines) const;

    UInt32 getNTheta () const;
    void setNTheta (UInt32 n);

    UInt32 getNRho () const;
    void setNRho (UInt32 n);
  protected:
    UInt32 n_theta;
    UInt32 n_rho;
};

#endif