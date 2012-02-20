#ifndef __REMOVE_DC_ESTIMATOR_H__
#define __REMOVE_DC_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class RemoveDCEstimator : public Estimator<Float64, Float64> {
  public:
    RemoveDCEstimator ();
    ~RemoveDCEstimator ();

    void compute (const Matrix<Float64>& input, Matrix<Float64>& output) const;

    bool getWindowed () const;
    void setWindowed (bool value);
    UInt8 getWindowAperture () const;
    void setWindowAperture (UInt8 size);

  protected:
    bool windowed;
    UInt8 window_aperture;
};

#endif