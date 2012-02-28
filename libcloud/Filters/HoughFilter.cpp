#include "HoughFilter.h"

#include "../Common/Vector.h"
#include "../Common/Plane.h"
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
  UInt32 n_theta = 200;
  UInt32 n_phi = 200;
  UInt32 n_rho = 200;

  double theta_step = 2*M_PI/(n_theta-1);
  double phi_step = 2*M_PI/(n_phi-1);
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
  output = input;
  std::cout << "shuffle" << std::endl;
  std::random_shuffle (output.begin (), output.end ());
  std::cout << "start processing" << std::endl;

  SInt32 min = 1000000000;
  SInt32 max = -1000000000;
  

  for (UInt32 i = 0; i < output.size ()-2; i += 3) {
    Plane plane (output[i], output[i+1], output[i+2]);

    UInt32 theta_idx = plane.getTheta ()/theta_step;
    UInt32 phi_idx = plane.getPhi ()/phi_step;
    // FIXME : n_rho/2 ?
    UInt32 rho_idx = plane.getRho ()/rho_step+n_rho/2;

/*    std::cout << "theta:" << plane.getTheta () << std::endl;
    std::cout << "phi:" << plane.getPhi () << std::endl;
    std::cout << "rho:" << plane.getRho () << std::endl;
    std::cout << "theta_idx:" << theta_idx << std::endl;
    std::cout << "phi_idx:" << phi_idx << std::endl;
    std::cout << "rho_idx:" << rho_idx << std::endl;*/
    accumulator[theta_idx][phi_idx][rho_idx]++;
//    std::cout << n << std::endl;
  }

  std::cout << "min:" << min << " max:" << max << std::endl;
#endif

  UInt32 theta_max = 0;
  UInt32 phi_max = 0;
  UInt32 rho_max = 0;
  max = 0;
  for (UInt32 i = 0; i < n_theta; ++i) {
    for (UInt32 j = 0; j < n_phi; ++j) {
      for (UInt32 k = 0; k < n_rho; ++k) {
        if (accumulator[i][j][k] > max) {
          max = accumulator[i][j][k];
          theta_max = i;
          phi_max = j;
          rho_max = k;
        }
      }
    }
  }

  std::cout << "theta_max:" << theta_max*theta_step << std::endl;
  std::cout << "phi_max:" << phi_max*phi_step << std::endl;
  std::cout << "rho_max:" << (rho_max-n_rho/2)*rho_step << std::endl;
}

void
HoughFilter::compute (const PointCloud& input, PointCloud& output, Plane& plane) const
{
    std::cout << "HoughFilter::compute" << std::endl;

    output = input;
    UInt32 n_theta = 200;
    UInt32 n_phi = 200;
    UInt32 n_rho = 200;

    double theta_step = 2*M_PI/(n_theta-1);
    double phi_step = 2*M_PI/(n_phi-1);
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
    output = input;
    std::cout << "shuffle" << std::endl;
    std::random_shuffle (output.begin (), output.end ());
    std::cout << "start processing" << std::endl;

    SInt32 min = 1000000000;
    SInt32 max = -1000000000;


    for (UInt32 i = 0; i < output.size ()-2; i += 3) {
      Plane plane (output[i], output[i+1], output[i+2]);

      UInt32 theta_idx = plane.getTheta ()/theta_step;
      UInt32 phi_idx = plane.getPhi ()/phi_step;
      // FIXME : n_rho/2 ?
      UInt32 rho_idx = plane.getRho ()/rho_step+n_rho/2;

  /*    std::cout << "theta:" << plane.getTheta () << std::endl;
      std::cout << "phi:" << plane.getPhi () << std::endl;
      std::cout << "rho:" << plane.getRho () << std::endl;
      std::cout << "theta_idx:" << theta_idx << std::endl;
      std::cout << "phi_idx:" << phi_idx << std::endl;
      std::cout << "rho_idx:" << rho_idx << std::endl;*/
      accumulator[theta_idx][phi_idx][rho_idx]++;
  //    std::cout << n << std::endl;
    }

    std::cout << "min:" << min << " max:" << max << std::endl;
  #endif

    UInt32 theta_max = 0;
    UInt32 phi_max = 0;
    UInt32 rho_max = 0;
    max = 0;
    for (UInt32 i = 0; i < n_theta; ++i) {
      for (UInt32 j = 0; j < n_phi; ++j) {
        for (UInt32 k = 0; k < n_rho; ++k) {
          if (accumulator[i][j][k] > max) {
            max = accumulator[i][j][k];
            theta_max = i;
            phi_max = j;
            rho_max = k;
          }
        }
      }
    }

    std::cout << "theta_max:" << theta_max*theta_step << std::endl;
    std::cout << "phi_max:" << phi_max*phi_step << std::endl;
    std::cout << "rho_max:" << (rho_max-n_rho/2)*rho_step << std::endl;
  plane = Plane ((rho_max-n_rho/2)*rho_step, theta_max*theta_step, phi_max*phi_step);
}