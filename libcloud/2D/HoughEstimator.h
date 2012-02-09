#ifndef __HOUGH_ESTIMATOR_H__
#define __HOUGH_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include "Line.h"
#include "../Common/Vector.h"

class HoughEstimator : public Estimator<UInt8, UInt8> {
  public:
    HoughEstimator ();
    ~HoughEstimator ();
    void compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const;

    void getLines (const Matrix<UInt8>& input, const Matrix<UInt8>& hough, std::vector<Line>& lines) const;
    void meanShift (Matrix<UInt8>& param_space, Vector& x, Matrix<UInt32>& tmp) const;

    UInt32 getNTheta () const;
    void setNTheta (UInt32 n);

    UInt32 getNRho () const;
    void setNRho (UInt32 n);
  protected:
    UInt32 n_theta;
    UInt32 n_rho;
};

#endif