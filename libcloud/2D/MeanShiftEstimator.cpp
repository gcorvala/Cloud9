#include "MeanShiftEstimator.h"

#include "../Common/Vector.h"

MeanShiftEstimator::MeanShiftEstimator ()
  :row_step(25)
  ,col_step(25)
  ,window_width(10)
  ,max_iterations(500)
  ,epsilon(1e-10)
{
}

MeanShiftEstimator::~MeanShiftEstimator ()
{
}

void
MeanShiftEstimator::compute (const Matrix<double>& input, Matrix<UInt8>& output) const
{
  output.resize (input.getRows (), input.getCols ());
  output.fill (0);

  for (UInt32 i = row_step; i <= input.getRows ()-row_step; i += row_step) {
    for (UInt32 j = col_step; j <= input.getCols ()-col_step; j += col_step) {
      Vector x (i, j);
      Vector x_old = x;
      UInt32 counter = 0;

      while (counter++ < max_iterations) {
        Vector sum_xig (0, 0);
        double sum_g = 0;

        for (UInt32 k = x.x-window_width; k <= x.x+window_width; ++k) {
          for (UInt32 l = x.y-window_width; l <= x.y+window_width; ++l) {
            double w;
            if (k < 0 || l < 0 || k >= input.getRows () || l >= input.getCols ()) {
              w = 0;
            }
            else {
              w = input (k, l);
            }
            Vector x_i (k, l);
            // FIXME : kernel ? exp ?
            double g_ = exp (-((x-x_i)/window_width).norm2 ());
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
        }
        x += Mh;

        if ((x_old-x).norm () <= 1e-5) {
          break;
        }
        x_old = x;
      }
      if (x_old != x)
        output (x.x, x.y) = 255;
    }
  }
}

/*void getModes (const Matrix<UInt8>& output, std::vector<Point>& modes) const;

UInt32 getRowStep () const;
void setRowStep (UInt32 step);
UInt32 getColStep () const;
void setColStep (UInt32 step);*/

UInt32
MeanShiftEstimator::getWindowWidth () const
{
  return window_width;
}

void
MeanShiftEstimator::setWindowWidth (double width)
{
  window_width = width;
}

/*UInt32 getMaxIterations () const;
void setMaxIterations (UInt32 iterations);
double getEpsilon () const;
void setEpsilon (double eps);*/