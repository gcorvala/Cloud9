#include "HoughEstimator.h"
#include "GaussianEstimator.h"
#include "MeanShiftEstimator.h"

HoughEstimator::HoughEstimator ()
  :n_theta(180)
  ,n_rho(256)
{
}

HoughEstimator::~HoughEstimator ()
{
}

void
HoughEstimator::compute (const Matrix<UInt8>& input, Matrix<UInt32>& output) const
{
  GaussianEstimator gaussian;
  // FIXME : M_PI is enough
  output.resize (n_theta, n_rho);

  double rho_max = 2*hypot (input.getRows (), input.getCols ());
  double rho_step = rho_max/(n_rho-1);
  double theta_init = 3/2*M_PI;
  double theta_step = 2*M_PI/(n_theta-1);

  for (UInt32 i = 0; i < input.getRows (); ++i) {
    for (UInt32 j = 0; j < input.getCols (); ++j) {
      if (input(i,j) == 255) {
        for (UInt32 k = 0; k < n_theta; ++k) {
          double theta = theta_init+k*theta_step;
          if (theta >= 2*M_PI) {
            theta -= 2*M_PI;
          }
          double rho = j*cos (theta)+i*sin (theta)+hypot (input.getRows (), input.getCols ());
          UInt32 l = rho/rho_step;
          output (k, l) += 1;
        }
      }
    }
  }
}

UInt32
HoughEstimator::getNTheta () const
{
  return n_theta;
}

void
HoughEstimator::setNTheta (UInt32 n)
{
  n_theta = n;
}

UInt32
HoughEstimator::getNRho () const
{
  return n_rho;
}

void
HoughEstimator::setNRho (UInt32 n)
{
  n_rho = n;
}
