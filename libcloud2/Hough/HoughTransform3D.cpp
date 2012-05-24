#include "HoughTransform3D.h"

#include <math.h>
#include <iostream>

HoughTransform3D::HoughTransform3D ()
{
  std::vector <Float32> min;
  std::vector <Float32> max;
  std::vector <Float32> bin_sizes;

  min.push_back (0);
  min.push_back (0);
  min.push_back (0);
  max.push_back (M_PI*2);
  max.push_back (M_PI*2);
  max.push_back (1000);
  bin_sizes.push_back (M_PI*2./100.);
  bin_sizes.push_back (M_PI*2./100.);
  bin_sizes.push_back (10);

  m_accumulator = Accumulator (min, max, bin_sizes);
}

HoughTransform3D::~HoughTransform3D ()
{
}

void
HoughTransform3D::setInput (const PointCloud& cloud)
{
  m_cloud = &cloud;
}

const PointCloud&
HoughTransform3D::getInput () const
{
  return *m_cloud;
}

void
HoughTransform3D::run ()
{
  std::vector <Float32> parameters;
  std::cout << "start processing" << std::endl;
  UInt32 ii = 0;
  for (PointCloud::const_iterator it = m_cloud->begin (); it != m_cloud->end (); ++it) {
    const Point &p = *it;
//    parameters.clear ();
/*    for (UInt32 i = 0; i < n_theta; ++i) {
      for (UInt32 j = 0; j < n_phi; ++j) {
        AccumulatorVote vote;
        double rho = p.x * cos (i * theta_step) * sin (j * phi_step);
        rho += p.y * sin (j * phi_step) * sin (i * theta_step);
        rho += p.z * cos (j * phi_step);
        UInt32 k = round (rho/rho_step);
        accumulator[i][j][k]++;
      }
    }*/
    //if (++ii % 1000 == 0) std::cout << ii << std::endl;
  }
}

const Accumulator&
HoughTransform3D::getOutput () const
{
  return m_accumulator;
}
