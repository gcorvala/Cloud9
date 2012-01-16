#ifndef __HILBERT_ESTIMATOR_H__
#define __HILBERT_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class HilbertEstimator : public Estimator<double, double> {
  public:
    HilbertEstimator ();
    ~HilbertEstimator ();

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