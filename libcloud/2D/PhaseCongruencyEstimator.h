#ifndef __PHASE_CONGRUENCY_ESTIMATOR_H__
#define __PHASE_CONGRUENCY_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"

class PhaseCongruencyEstimator : public Estimator<UInt8, UInt8> {
  public:
    PhaseCongruencyEstimator ();
    ~PhaseCongruencyEstimator ();

    void compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const;

    void setAperture (UInt8 aperture);

  protected:
    UInt8 window_aperture;
};

#endif