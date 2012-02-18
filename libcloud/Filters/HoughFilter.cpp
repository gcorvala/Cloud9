#include "HoughFilter.h"

#include "../Common/Vector.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

HoughFilter::HoughFilter ()
{
}

HoughFilter::~HoughFilter ()
{
}

void
HoughFilter::run (PointCloud& cloud) const
{
}

void
HoughFilter::compute (const PointCloud& input, PointCloud& output) const
{
  std::cout << "HoughFilter::compute" << std::endl;

  output = input;
  UInt32 n_theta = 100;
  UInt32 n_phi = 100;
  UInt32 n_rho = 100;

  double theta_step = M_PI/(n_theta-1);
  double phi_step = M_PI/(n_phi-1);
  double diameter = 2*(Vector (input.getMax ()) - Vector (input.getMin ())).norm ();
  double rho_step = diameter/(n_rho-1);

  std::cout << "construct accumulator" << std::endl;

  UInt32 ***accumulator = new UInt32**[n_theta];

  for (UInt32 i = 0; i < n_theta; ++i) {
    accumulator[i] = new UInt32*[n_phi];
    for (UInt32 j = 0; j < n_phi; ++j) {
      accumulator[i][j] = new UInt32[n_rho];
      for (UInt32 k = 0; k < n_rho; ++k) {
        accumulator[i][j][k] = 0;
      }
    }
  }

#if 0
  // Standard Hough Transform (SHT)
  std::cout << "start processing" << std::endl;
  UInt32 ii = 0;
  for (PointCloud::const_iterator it = input.begin (); it != input.end (); ++it) {
    const Point &p = *it;
    for (UInt32 i = 0; i < n_theta; ++i) {
      for (UInt32 j = 0; j < n_phi; ++j) {
        double rho = p.x * cos (i * theta_step) * sin (j * phi_step);
        rho += p.y * sin (j * phi_step) * sin (i * theta_step);
        rho += p.z * cos (j * phi_step);
        UInt32 k = round (rho/rho_step);
        accumulator[i][j][k]++;
      }
    }
    if (++ii % 1000 == 0) std::cout << ii << std::endl;
  }
#else
  // Randomized Hough Transform (RHT)
//  std::cout << "list construction" << std::endl;
//  std::list<Point> cloud (input.begin (), input.end ());
  output = input;
  std::cout << "shuffle" << std::endl;
  std::random_shuffle (output.begin (), output.end ());
  std::cout << "start processing" << std::endl;

  for (PointCloud::const_iterator it = output.begin (); it != output.end (); ++it) {
    Vector p1 = *it;
    if (++it == output.end ()) break;
    Vector p2 = *it;
    if (++it == output.end ()) break;
    Vector p3 (*it);

    /*
    rho = px*cos(theta)*sin(phi)+py*sin(phi)*sin(theta)+pz*cos(phi)
    px*cos(theta)*sin(phi) = rho-py*sin(phi)*sin(theta)-pz*cos(phi)
    */
    Vector n = ((p3-p2).cross (p1-p2));

    Float64 theta = n.angle (Vector (1, 0, 0));
    Float64 phi = n.angle (Vector (0, 0, -1));
    Float64 rho = n.dot (p1);
    UInt32 theta_idx = theta/theta_step;
    UInt32 phi_idx = phi/phi_step;
    UInt32 rho_idx = rho/rho_step;
    std::cout << theta_idx << " " << phi_idx << " " << rho_idx << std::endl;
    accumulator[theta_idx][phi_idx][rho_idx]++;
    /*for (UInt32 i = 0; i < n_theta; ++i) {
      for (UInt32 j = 0; j < n_phi; ++j) {
        UInt32 k = round (rho/rho_step);
        accumulator[i][j][0]++;
      }
    }*/
  }
#endif
}