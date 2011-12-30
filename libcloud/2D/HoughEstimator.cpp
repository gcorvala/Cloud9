#include "HoughEstimator.h"

HoughEstimator::HoughEstimator ()
  :n_theta(1024)
  ,n_rho(1024)
{
}

HoughEstimator::~HoughEstimator ()
{
}

void
HoughEstimator::setInputMatrix (const Matrix<UInt8>& _matrix)
{
  Estimator<UInt8, UInt8>::setInputMatrix (_matrix);
  //n_rho = matrix->getRows ();
}

void
HoughEstimator::compute (Matrix<UInt8>& output) const
{
  Matrix<UInt32> accumulator (n_theta, n_rho);

  UInt32 rho_max = 2*sqrt (matrix->getRows ()*matrix->getRows ()+matrix->getCols ()*matrix->getCols ());
  UInt32 rho_step = rho_max/(n_rho-1);

  for (UInt32 i = 0; i < matrix->getRows (); ++i) {
    for (UInt32 j = 0; j < matrix->getCols (); ++j) {
      if (matrix->at(i,j) == 255) {
        for (UInt32 k = 0; k < n_theta; ++k) {
          float theta = k*(M_PI/(n_theta-1));
          UInt32 rho = j*cos (theta)+i*sin (theta);
          UInt32 theta_idx = k;
          UInt32 rho_idx = rho/rho_step;
          accumulator(theta_idx, rho_idx)++;
        }
      }
    }
  }

  Matrix<double> t;
  t = accumulator;
  for (UInt32 i = 0; i < t.getRows (); ++i) {
    for (UInt32 j = 0; j < t.getCols (); ++j) {
      if (t(i,j) > 255)
        t(i,j) = 255;
    }
  }

  output = t;
}

void
HoughEstimator::getLines (Matrix<UInt8>& hough, std::vector<Line>& lines) const
{
  lines.clear ();

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

  lines.push_back (Line (col*rho_step, row*theta_step));
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
