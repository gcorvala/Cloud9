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

  in = (double*) fftw_alloc_real (input.getRows ()*input.getCols ());

  for (UInt32 i = 0; i < input.getRows (); ++i) {
    for (UInt32 j = 0; j < input.getCols (); ++j) {
      in[i*input.getCols ()+j] = input (i, j);
    }
  }

  out = (fftw_complex*) fftw_malloc (sizeof (fftw_complex)*input.getRows ()*input.getCols ());

  p = fftw_plan_dft_r2c_2d (input.getRows (), input.getCols (), in, out, FFTW_ESTIMATE);

  fftw_execute(p);

  output.resize (input.getRows (), input.getCols ()/2+1);

  for (UInt32 i = 0; i < output.getRows (); ++i) {
    for (UInt32 j = 0; j < output.getCols (); ++j) {
      double c1 = *out[2*i*output.getCols ()+2*j];
      double c2 = *out[2*i*output.getCols ()+2*j+1];
      output (i, j) = std::complex<double> (c1, c2);
    }
  }

  fftw_destroy_plan(p);
  fftw_free(in);
  fftw_free(out);
}
