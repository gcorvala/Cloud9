#include "MeanShiftEstimator.h"

#include "../Common/Vector.h"
#include "../Common/Utils.h"

MeanShiftEstimator::MeanShiftEstimator ()
  :row_step(15)
  ,col_step(15)
  ,window_width(15)
  ,max_iterations(300)
  ,epsilon(1e-10)
{
}

MeanShiftEstimator::~MeanShiftEstimator ()
{
}

void
MeanShiftEstimator::compute (const Matrix<Float64>& input, Matrix<UInt8>& output) const
{
  std::cout << "MeanShiftEstimator::compute" << std::endl;
  output.resize (input.getRows (), input.getCols ());
  output.fill (0);

#if 1
  for (UInt32 i = row_step; i <= input.getRows ()-row_step; i += row_step) {
    for (UInt32 j = col_step; j <= input.getCols ()-col_step; j += col_step) {
      Vector x (i, j);
      Vector x_old = x;
      UInt32 counter = 0;

      while (counter++ < max_iterations) {
        Vector sum_xig (0, 0);
        Float64 sum_g = 0;

        for (UInt32 k = x.x-window_width; k <= x.x+window_width; ++k) {
          for (UInt32 l = x.y-window_width; l <= x.y+window_width; ++l) {
            Float64 w;
            if (k < 0 || l < 0 || k >= input.getRows () || l >= input.getCols ()) {
              w = 0;
            }
            else {
              w = input (k, l);
            }
            Vector x_i (k, l);
            // FIXME : kernel ? exp ?
            Float64 g_ = exp (-((x-x_i)/window_width).norm2 ());
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

        //output (x.x, x.y) = 255;
        if ((x_old-x).norm () <= 1e-5) {
          break;
        }
        x_old = x;
      }
      if (x_old != x) {
        // FIXME : why normalize ?
        output (x.x, x.y) = (Float64) (input (x.x, x.y)/input.max ())*255;
      }

    }
  }
#else
  for (UInt32 i = 0; i <= input.getRows (); i+=5) {
    std::cout << "i:" << i << std::endl;
    for (UInt32 j = 0; j <= input.getCols (); j+=5) {
      Vector x (i, j);
      Vector sum_xig (0, 0);
      Float64 sum_g = 0;

      for (UInt32 k = x.x-window_width; k <= x.x+window_width; ++k) {
        for (UInt32 l = x.y-window_width; l <= x.y+window_width; ++l) {
          Float64 w;
          if (k < 0 || l < 0 || k >= input.getRows () || l >= input.getCols ()) {
            w = 0;
          }
          else {
            w = input (k, l);
          }
          Vector x_i (k, l);
          // FIXME : kernel ? exp ?
          Float64 g_ = exp (-((x-x_i)/window_width).norm2 ());
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

      output(i,j) = 10*Mh.norm ();
    }
  }
#endif
}

void
MeanShiftEstimator::compute (const Matrix<Float64>& input, Matrix<UInt8>& output, std::vector<Point>& modes) const
{
  compute (input, output);
  modes.clear ();

  for (UInt32 i = 0; i < output.getRows (); ++i) {
    for (UInt32 j = 0; j < output.getCols (); ++j) {
      UInt8 val = output (i, j);
      if (val > 0) {
        modes.push_back (Point (i, j, val));
      }
    }
  }

  sort (modes.begin (), modes.end (), comparePointsByZAxis);
}

UInt32
MeanShiftEstimator::getRowStep () const
{
  return row_step;
}

void
MeanShiftEstimator::setRowStep (UInt32 step)
{
  row_step = step;
}

UInt32
MeanShiftEstimator::getColStep () const
{
  return col_step;
}

void
MeanShiftEstimator::setColStep (UInt32 step)
{
  col_step = step;
}

UInt32
MeanShiftEstimator::getWindowWidth () const
{
  return window_width;
}

void
MeanShiftEstimator::setWindowWidth (Float64 width)
{
  window_width = width;
}

UInt32
MeanShiftEstimator::getMaxIterations () const
{
  return max_iterations;
}

void
MeanShiftEstimator::setMaxIterations (UInt32 iterations)
{
  max_iterations = iterations;
}

Float64
MeanShiftEstimator::getEpsilon () const
{
  return epsilon;
}

void
MeanShiftEstimator::setEpsilon (Float64 eps)
{
  epsilon = eps;
}
