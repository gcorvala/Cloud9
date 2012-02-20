#include "PhaseCongruencyEstimator.h"

#include "FourierEstimator.h"
#include "HilbertEstimator.h"
#include "RemoveDCEstimator.h"

PhaseCongruencyEstimator::PhaseCongruencyEstimator ()
  :window_aperture(2)
{
}

PhaseCongruencyEstimator::~PhaseCongruencyEstimator ()
{
}

void
PhaseCongruencyEstimator::compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const
{
  FourierEstimator fourier;
  HilbertEstimator hilbert;
  RemoveDCEstimator remove_dc;
  UInt8 window_size = window_aperture*2-1;
  Matrix<Float64> mf_result;
  Matrix<Float64> mh_result;
  Matrix<Float64> mf_result_2;
  Matrix<Float64> mh_result_2;
  Matrix<Float64> energy;
  Matrix<Float64> s;
  Matrix<Float64> window;

  remove_dc.setWindowed (true);
  remove_dc.setWindowAperture (window_aperture);
  remove_dc.compute (input, mf_result);

  hilbert.setWindowed (true);
  hilbert.setWindowAperture (window_aperture);
  hilbert.compute (input, mh_result);


  mf_result.mul (mf_result, mf_result_2);
  mh_result.mul (mh_result, mh_result_2);

  energy = mf_result_2+mh_result_2;

  energy.sqrt (s);

  for (UInt32 i = 0; i < s.getRows (); ++i) {
    for (UInt32 j = 0; j < s.getCols (); ++j) {
      window = input.getSubMatrix (i-window_aperture+1, j-window_aperture+1, window_size, window_size);
      Matrix<std::complex<Float64> > fourier_coefs;
      fourier.compute (window, fourier_coefs);
      Float64 sum = 0;
      for (UInt32 k = 0; k < fourier_coefs.getRows (); ++k) {
        for (UInt32 l = 0; l < fourier_coefs.getCols (); ++l) {
          sum += abs (fourier_coefs (k, l));
        }
      }
      s (i, j) /= sum*(1./(window.getCols ()*window.getRows ()));
    }
  }

  s -= s.min ();
  s /= s.max ();
  s *= 255;

  output = s;
}

void
PhaseCongruencyEstimator::setAperture (UInt8 aperture)
{
  window_aperture = aperture;
}