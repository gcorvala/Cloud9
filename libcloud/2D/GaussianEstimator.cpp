#include "GaussianEstimator.h"

#include <iostream>

GaussianEstimator::GaussianEstimator ()
  :aperture(3)
  ,sigma(1.4)
{
  generateFilter ();
}

GaussianEstimator::~GaussianEstimator ()
{
}

void
GaussianEstimator::compute (const Matrix<UInt32>& input, Matrix<UInt32>& output) const
{
  input.convolve (gaussian_filter, output);
}

void
GaussianEstimator::setAperture (UInt32 _aperture)
{
  aperture = _aperture;
  generateFilter ();
}

UInt32
GaussianEstimator::getAperture () const
{
  return aperture;
}

void
GaussianEstimator::setSigma (double s)
{
  sigma = s;
  generateFilter ();
}

double
GaussianEstimator::getSigma () const
{
  return sigma;
}

Matrix<double>
GaussianEstimator::getFilter () const
{
  return gaussian_filter;
}

void
GaussianEstimator::generateFilter ()
{
  gaussian_filter.resize (aperture*2-1, aperture*2-1);

  for (UInt32 i = 0; i < gaussian_filter.getRows (); ++i) {
    for (UInt32 j = 0; j < gaussian_filter.getCols (); ++j) {
      UInt32 x = j-aperture+1;
      UInt32 y = i-aperture+1;
      gaussian_filter(i, j) = 1/(2*M_PI*sigma*sigma)*exp (-(float)(x*x+y*y)/(2*sigma*sigma));
    }
  }
}