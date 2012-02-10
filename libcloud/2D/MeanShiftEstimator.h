#ifndef __MeanShift_ESTIMATOR_H__
#define __MeanShift_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include "../Common/Point.h"

class MeanShiftEstimator : public Estimator<double, UInt8> {
  public:
    MeanShiftEstimator ();
    ~MeanShiftEstimator ();
    void compute (const Matrix<double>& input, Matrix<UInt8>& output) const;

    void getModes (const Matrix<UInt8>& output, std::vector<Point>& modes) const;

    UInt32 getRowStep () const;
    void setRowStep (UInt32 step);
    UInt32 getColStep () const;
    void setColStep (UInt32 step);
    UInt32 getWindowWidth () const;
    void setWindowWidth (double width);
    UInt32 getMaxIterations () const;
    void setMaxIterations (UInt32 iterations);
    double getEpsilon () const;
    void setEpsilon (double eps);

  protected:
    UInt32 row_step;
    UInt32 col_step;
    UInt32 window_width;
    UInt32 max_iterations;
    double epsilon;
};

#endif