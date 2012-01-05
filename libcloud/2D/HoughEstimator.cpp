#include "HoughEstimator.h"

HoughEstimator::HoughEstimator ()
  :n_theta(256)
  ,n_rho(256)
{
}

HoughEstimator::~HoughEstimator ()
{
}

void
HoughEstimator::compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const
{
  // FIXME : M_PI is enough
  Matrix<UInt32> accumulator (n_theta, n_rho);

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
          accumulator (k, l) += 1;
        }
      }
    }
  }

  double max = accumulator.max ();
  output.resize (accumulator.getRows (), accumulator.getCols ());
  for (UInt32 i = 0; i < accumulator.getRows (); ++i) {
    for (UInt32 j = 0; j < accumulator.getCols (); ++j) {
      output (i, j) = sqrt (accumulator (i, j))/sqrt (max)*255;
    }
  }
}

void
HoughEstimator::getLines (Matrix<UInt8>& hough, std::vector<Line>& lines) const
{
/*  lines.clear ();

  UInt32 rho_max = 2*sqrt (matrix->getRows ()*matrix->getRows ()+matrix->getCols ()*matrix->getCols ());
  UInt32 rho_step = rho_max/(n_rho-1);
  double theta_step = M_PI/(n_theta-1);

  UInt32 row, col;
  hough.max (row, col);
  //hough(row, col) = 0;

  std::cout << "theta = " << row << std::endl;
  std::cout << "rho = " << col << std::endl;
  std::cout << "theta = " << row*theta_step << std::endl;
  std::cout << "rho = " << col*rho_step << std::endl;

  lines.push_back (Line (col*rho_step, row*theta_step));*/
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
