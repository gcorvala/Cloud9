#include "HoughEstimator.h"
#include "GaussianEstimator.h"

HoughEstimator::HoughEstimator ()
  :n_theta(180)
  ,n_rho(256)
{
}

HoughEstimator::~HoughEstimator ()
{
}

void
HoughEstimator::compute (const Matrix<UInt8>& input, Matrix<UInt8>& output) const
{
  GaussianEstimator gaussian;
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

  std::vector<Line> lines;

  Vector x;
  UInt32 step = 30;

  double max = accumulator.max ();
  output.resize (accumulator.getRows (), accumulator.getCols ());
  for (UInt32 i = 0; i < accumulator.getRows (); ++i) {
    for (UInt32 j = 0; j < accumulator.getCols (); ++j) {
      output (i, j) = accumulator (i, j)/max*255;
    }
  }
  gaussian.setAperture (9);
  gaussian.setSigma (2.3);
  gaussian.compute (output, output);

  Matrix<UInt32> tmp = output;
  tmp.fill (0);

  for (UInt32 i = step; i <= accumulator.getRows ()-step; i += step) {
    for (UInt32 j = step; j <= accumulator.getCols ()-step; j += step) {
      x = Vector (i, j);
      meanShift (output, x, tmp);
    }
  }

  output = tmp;
  //accumulator = tmp;

/*  double max = accumulator.max ();
  output.resize (accumulator.getRows (), accumulator.getCols ());
  for (UInt32 i = 0; i < accumulator.getRows (); ++i) {
    for (UInt32 j = 0; j < accumulator.getCols (); ++j) {
      output (i, j) = sqrt (accumulator (i, j))/sqrt (max)*255;
    }
  }*/
}

void
HoughEstimator::getLines (const Matrix<UInt8>& input, const Matrix<UInt8>& hough, std::vector<Line>& lines) const
{
  lines.clear ();

  double rho_max = 2*hypot (input.getRows (), input.getCols ());
  double rho_step = rho_max/(n_rho-1);
  double theta_init = 3/2*M_PI;
  double theta_step = 2*M_PI/(n_theta-1);

  UInt32 row, col;
  Matrix<UInt8> tmp;
  tmp = hough;
  tmp.max (row, col);
  tmp (row, col) = 0;
  tmp.max (row, col);
  tmp (row, col) = 0;
  tmp.max (row, col);

  std::cout << "theta = " << row << std::endl;
  std::cout << "rho = " << col << std::endl;
  std::cout << "theta = " << row*theta_step << std::endl;
  std::cout << "rho = " << col*rho_step << std::endl;

  lines.push_back (Line (col*rho_step, row*theta_step));
}

static double g (double x) {
  double result;
  //result = 1./2.*exp (-1./2.*x);
//  if (abs (x) <= 10) {
  result = exp (-x); // gaussian
//  result = 1-x; // epan
//  }
//  else {
//    result = 0;
//  }
  return result;
}

void
HoughEstimator::meanShift (Matrix<UInt8>& param_space, Vector& x, Matrix<UInt32>& tmp) const
{
  UInt8 h = 12;
  UInt32 counter = 0;
  //Matrix<UInt8> tmp (param_space.getRows (), param_space.getCols ());// = param_space;
  //tmp.fill (0);

  std::cout << "meanShift (" << x.x << "," << x.y << ")" << std::endl;

  //tmp (x.x, x.y) = 0;

  Vector x_old = x;

  while (counter++ < 500) {
  //while (true) {
    Vector sum_xig (0, 0);
    double sum_g = 0;

    for (UInt32 k = x.x-h; k <= x.x+h; ++k) {
      for (UInt32 l = x.y-h; l <= x.y+h; ++l) {
        double w;
        if (k < 0 || l < 0 || k >= param_space.getRows () || l >= param_space.getCols ()) {
          w = 0;
        }
        else {
          w = param_space (k, l);
        }
        Vector x_i (k, l);
        double g_ = g (((x-x_i)/h).norm2 ());
        sum_xig += x_i*g_*w;
        sum_g += g_*w;
      }
    }
    Vector Mh;
    if (sum_xig == 0 || sum_g == 0) {
      Mh = Vector ();
    }
    else {
      Mh = (sum_xig/sum_g)-x;
//      Mh.normalize ();
    }

    //std::cout << "|Mh|:" << Mh.norm () << " Mh.x:" << Mh.x << " Mh.y:" << Mh.y << " Mh.z:" << Mh.z << std::endl;
    x += Mh;

    if ((x_old-x).norm () <= 1e-10) break;
    x_old = x;

    //std::cout << "counter: " << counter << " x: (" << x.x << "," << x.y << ")" << std::endl;
    //tmp (x.x, x.y) = 0;
  }
  if (x_old != x)
    tmp (x.x, x.y) = 255;

  //param_space = tmp;
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
