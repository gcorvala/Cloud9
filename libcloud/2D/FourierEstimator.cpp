#include "FourierEstimator.h"
#include <fftw3.h>

FourierEstimator::FourierEstimator ()
{
}

FourierEstimator::~FourierEstimator ()
{
}

void
FourierEstimator::compute (const Matrix<double>& input, Matrix<std::complex<double> >& output) const
{
  double *in;
  fftw_complex *out;
  fftw_plan p;

  // FIXME : fftw3.3 on ubuntu ?
  //in = (double*) fftw_alloc_real (input.getRows ()*input.getCols ());
  in = (double*) fftw_malloc (sizeof (double)*input.getRows ()*input.getCols ());

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
        output (i, j) = std::complex<double> (c[0], c[1]);
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
