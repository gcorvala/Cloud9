#ifndef __HOUGH_2D_H__
#define __HOUGH_2D_H__

#include "PointCloudT.h"
#include "../2D/Matrix.h"

template <typename T>
class Hough2D {
  public:
    Hough2D ();
    ~Hough2D ();

    void compute (const PointCloudT < Point2D <T> >& cloud, Matrix <UInt32>& output, std::vector <Float64>& rho_steps, std::vector <Float64>& theta_steps) const;
    void remove (const PointCloudT < Point2D <T> >& cloud, Matrix <UInt32>& output, const std::vector <Float64>& rho_steps, const std::vector <Float64>& theta_steps) const;

    UInt32 getNTheta () const;
    void setNTheta (UInt32 n);

    UInt32 getNRho () const;
    void setNRho (UInt32 n);

  protected:
    UInt32 m_n_theta;
    UInt32 m_n_rho;
};

template <typename T>
Hough2D <T>::Hough2D ()
  :m_n_theta (400)
  ,m_n_rho (400)
{
}

template <typename T>
Hough2D <T>::~Hough2D ()
{
}

template <typename T>
void
Hough2D <T>::compute (const PointCloudT < Point2D <T> >& cloud, Matrix <UInt32>& output, std::vector <Float64>& rho_steps, std::vector <Float64>& theta_steps) const
{
  typename PointCloudT < Point2D <T> >::const_iterator it;

  output.resize (m_n_theta, m_n_rho);

  Point2D <T> min (std::numeric_limits <T>::max (), std::numeric_limits <T>::max ());
  Point2D <T> max (std::numeric_limits <T>::min (), std::numeric_limits <T>::min ());

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    if (it->x > max.x) {
      max.x = it->x;
    }
    if (it->y > max.y) {
      max.y = it->y;
    }
    if (it->x < min.x) {
      min.x = it->x;
    }
    if (it->y < min.y) {
      min.y = it->y;
    }
  }

  Float64 h = min.distanceTo (max);
  Float64 theta_step = M_PI/(m_n_theta-1);
  Float64 rho_step = 2*h/(m_n_rho-1);

  std::cout << "theta step: " << theta_step << std::endl;
  std::cout << "rho step: " << rho_step << std::endl;
  std::cout << "h: " << h << std::endl;

  rho_steps.resize (m_n_rho);
  theta_steps.resize (m_n_theta);

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    for (UInt32 k = 0; k < m_n_theta; ++k) {
      Float64 theta = k*theta_step;
      if (theta >= 2.*M_PI) {
        theta -= 2.*M_PI;
      }

      Float64 rho = it->x*cos (theta)+it->y*sin (theta)+h;
      UInt32 l = rho/rho_step;

      output (k, l) += 1;
    }
  }

  for (UInt32 i = 0; i < m_n_rho; ++i) {
    rho_steps[i] = rho_step*i-h;
  }
  for (UInt32 i = 0; i < m_n_theta; ++i) {
    theta_steps[i] = theta_step*i;
  }
}

template <typename T>
void
Hough2D <T>::remove (const PointCloudT < Point2D <T> >& cloud, Matrix <UInt32>& output, const std::vector <Float64>& rho_steps, const std::vector <Float64>& theta_steps) const
{
  typename PointCloudT < Point2D <T> >::const_iterator it;
  Float64 theta_step = theta_steps[1];
  Float64 rho_step = rho_steps[1]-rho_steps[0];
  Float64 h = -rho_steps[0];

  std::cout << "theta step: " << theta_step << std::endl;
  std::cout << "rho step: " << rho_step << std::endl;
  std::cout << "h: " << h << std::endl;

//    Float64 rho_step = 2*h/(m_n_rho-1);

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    for (UInt32 k = 0; k < m_n_theta; ++k) {
      Float64 theta = k*theta_step;
      if (theta >= 2.*M_PI) {
        theta -= 2.*M_PI;
      }

      Float64 rho = it->x*cos (theta)+it->y*sin (theta)+h;
      UInt32 l = rho/rho_step;

      output (k, l) -= 1;
    }
  }
}

template <typename T>
UInt32
Hough2D <T>::getNTheta () const
{
  return m_n_theta;
}

template <typename T>
void
Hough2D <T>::setNTheta (UInt32 n)
{
  m_n_theta = n;
}

template <typename T>
UInt32
Hough2D <T>::getNRho () const
{
  return m_n_rho;
}

template <typename T>
void
Hough2D <T>::setNRho (UInt32 n)
{
  m_n_rho = n;
}

#endif