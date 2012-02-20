#ifndef __MeanShift_ESTIMATOR_H__
#define __MeanShift_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include "../Common/Point.h"

class MeanShiftEstimator : public Estimator<Float64, UInt8> {
  public:
    MeanShiftEstimator ();
    ~MeanShiftEstimator ();
    void compute (const Matrix<Float64>& input, Matrix<UInt8>& output) const;
    void compute (const Matrix<Float64>& input, Matrix<UInt8>& output, std::vector<Point>& modes) const;

    UInt32 getRowStep () const;
    void setRowStep (UInt32 step);
    UInt32 getColStep () const;
    void setColStep (UInt32 step);
    UInt32 getWindowWidth () const;
    void setWindowWidth (Float64 width);
    UInt32 getMaxIterations () const;
    void setMaxIterations (UInt32 iterations);
    Float64 getEpsilon () const;
    void setEpsilon (Float64 eps);

  protected:
    UInt32 row_step;
    UInt32 col_step;
    UInt32 window_width;
    UInt32 max_iterations;
    Float64 epsilon;
};

#endif