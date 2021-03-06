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
  output.resize (n_theta, n_rho);

  Float64 theta_init = 3./2.*M_PI;
  Float64 theta_step = getThetaStep ();
  Float64 rho_step = getRhoStep (input);

  for (UInt32 i = 0; i < input.getRows (); ++i) {
    for (UInt32 j = 0; j < input.getCols (); ++j) {
      if (input(i,j) == 255) {
        for (UInt32 k = 0; k < n_theta; ++k) {
          Float64 theta = theta_init+k*theta_step;
          if (theta >= 2*M_PI) {
            theta -= 2*M_PI;
          }
          Float64 rho = j*cos (theta)+i*sin (theta)+hypot (input.getRows (), input.getCols ());
          UInt32 l = rho/rho_step;
          output (k, l) += 1;
        }
      }
    }
  }
}

void
HoughEstimator::compute (const PointCloud& cloud, Matrix<UInt32>& output) const
{
#if 0
  PointCloud t = cloud;
  std::random_shuffle (t.begin (), t.end ());

  output.resize (n_theta, n_rho);

  for (UInt32 i = 0; i < t.size (); i += 2) {
    Line line (t[i], t[i+1]);
    
  }
#else
  PointCloud::const_iterator it;

  output.resize (n_theta, n_rho);

  //Float64 theta_init = 3./2.*M_PI;
  Float64 theta_init = 0;
  Float64 theta_step = getThetaStep ();
  Float64 rho_step = getRhoStep (cloud);
  std::cout << "theta_step:" << theta_step << std::endl;
  std::cout << "rho_step:" << rho_step << std::endl;

  int i = 0;
  Point min = cloud.getMin ();
  Point max = cloud.getMax ();
  Point center = (Vector (min)+Vector (max))/2;
  Float64 h = min.distanceTo (max);

  std::cout << "cloud size:" << cloud.size () << std::endl;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    std::cout << ++i << std::endl;
    //Point p = Vector (*it)-Vector (min);
    for (UInt32 k = 0; k < n_theta; ++k) {
      Float64 theta = theta_init+k*theta_step;
      if (theta >= 2.*M_PI) {
        theta -= 2.*M_PI;
      }
      Float64 rho = it->x*cos (theta)+it->y*sin (theta)+h;
      //Float64 rho = p.x*cos (theta)+p.y*sin (theta)+h;
      UInt32 l = rho/rho_step;
      output (k, l) += 1;
    }
  }
#endif
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

Float64
HoughEstimator::getThetaStep () const
{
  // FIXME : M_PI is enough -> done ?
  return M_PI/(n_theta-1);
}

Float64
HoughEstimator::getRhoStep (const Matrix<UInt8>& input) const
{
  Float64 rho_max = 2*hypot (input.getRows (), input.getCols ());
  return rho_max/(n_rho-1);
}

Float64
HoughEstimator::getRhoStep (const PointCloud& cloud) const
{
  return 2*(cloud.getMin ().distanceTo (cloud.getMax ()))/(n_rho-1);
}
