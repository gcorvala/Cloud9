#include "PhaseCongruencyEstimator.h"

#include "FourierEstimator.h"

PhaseCongruencyEstimator::PhaseCongruencyEstimator ()
  :window_aperture(5)
{
}

PhaseCongruencyEstimator::~PhaseCongruencyEstimator ()
{
}

void
PhaseCongruencyEstimator::compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const
{
  FourierEstimator fourier;
  UInt8 window_size = window_aperture*2-1;
  Matrix<double> mf (window_size, window_size);

  UInt32 window_size_2 = mf.getRows ()*mf.getCols ();

  for (UInt32 i = 0; i < mf.getRows (); ++i) {
    for (UInt32 j = 0; j < mf.getCols (); ++j) {
      if (i == window_size/2) {
        mf (i, j) = 1.-(1./window_size_2);
      }
      else {
        mf (i, j) = -1./window_size_2;
      }
    }
  }

  Matrix<double> mh (window_size, window_size);

  double factor = 2./(mh.getRows ()*mh.getCols ());

  for (UInt32 i = 0; i < mh.getRows (); ++i) {
    for (UInt32 j = 0; j < mh.getCols (); ++j) {
      mh (i, j) = factor*(1./tan (M_PI/mh.getCols ())*j+1./tan (M_PI/mh.getRows ())*i);
    }
  }

  Matrix<double> mf_result;
  input.convolve (mf, mf_result);

  Matrix<double> mh_result;
  input.convolve (mh, mh_result);

  Matrix<double> mf_result_2;
  Matrix<double> mh_result_2;

  mf_result.mul (mf_result, mf_result_2);
  mh_result.mul (mh_result, mh_result_2);

  Matrix<double> energy;

  energy = mf_result_2+mh_result_2;

  Matrix<double> s;

  energy.sqrt (s);

  Matrix<double> window;

  for (UInt32 i = 0; i < s.getRows (); ++i) {
    for (UInt32 j = 0; j < s.getCols (); ++j) {
      window = input.getSubMatrix (i-window_aperture+1, j-window_aperture+1, window_size, window_size);
      Matrix<std::complex<double> > fourier_coefs;
      fourier.compute (window, fourier_coefs);
      double sum = 0;
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
