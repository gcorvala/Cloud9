#include "FourierEstimator.h"
#include <fftw3.h>

FourierEstimator::FourierEstimator ()
{
}

FourierEstimator::~FourierEstimator ()
{
}

void
FourierEstimator::compute (const Matrix<Float64>& input, Matrix<std::complex<Float64> >& output) const
{
  Float64* in;
  fftw_complex* out;
  fftw_plan p;

  in = (Float64*) fftw_malloc (sizeof (Float64)*input.getRows ()*input.getCols ());

  for (UInt32 i = 0; i < input.getRows (); ++i) {
    for (UInt32 j = 0; j < input.getCols (); ++j) {
      in[i*input.getCols ()+j] = input (i, j);
    }
  }

  out = (fftw_complex*) fftw_malloc (sizeof (fftw_complex)*input.getRows ()*input.getCols ());

  p = fftw_plan_dft_r2c_2d (input.getRows (), input.getCols (), in, out, FFTW_ESTIMATE);

  fftw_execute(p);

  output.resize (input.getRows (), input.getCols ());

  UInt32 offset = 0;

  for (UInt32 i = 0; i < output.getRows (); ++i) {
    UInt32 pos = input.getCols ()/2;

    for (UInt32 j = 0; j < output.getCols (); ++j) {
      if (j < input.getCols ()/2+1) {
        fftw_complex& c = out[offset++];
        output (i, j) = std::complex<Float64> (c[0], c[1]);
      }
      else {
        UInt32 col = pos--;
        if (i == 0) {
          output (i, j) = conj (output (i, col));
        }
        else {
          output (i, j) = conj (output (input.getRows ()-i, col));
        }
      }
    }
  }

  fftw_destroy_plan(p);
  fftw_free(in);
  fftw_free(out);
}
