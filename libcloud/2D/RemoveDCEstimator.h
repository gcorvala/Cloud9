#ifndef __REMOVE_DC_ESTIMATOR_H__
#define __REMOVE_DC_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class RemoveDCEstimator : public Estimator<double, double> {
  public:
    RemoveDCEstimator ();
    ~RemoveDCEstimator ();

    void compute (const Matrix<double>& input, Matrix<double>& output) const;

    bool getWindowed () const;
    void setWindowed (bool value);
    UInt8 getWindowAperture () const;
    void setWindowAperture (UInt8 size);

  protected:
    bool windowed;
    UInt8 window_aperture;
};

#endif