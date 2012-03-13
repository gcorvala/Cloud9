#ifndef __THRESHOLD_ESTIMATOR_H__
#define __THRESHOLD_ESTIMATOR_H__

#if 0

#include "Estimator.h"
#include "Matrix.h"

class ThresholdEstimator : public Estimator<Float64, Float64> {
  public:
    ThresholdEstimator ();
    ~ThresholdEstimator ();
    void compute (const Matrix<Float64>& input, Matrix<Float64>& output) const;

    Float64 getThreshold () const;
    void setThreshold (Float64 t);
  protected:
    Float64 threshold;
};

#else

#include "Estimator.h"
#include "Matrix.h"

template <typename T>
class ThresholdEstimator : public Estimator<T, T> {
  public:
    ThresholdEstimator ();
    ~ThresholdEstimator ();
    void compute (const Matrix<T>& input, Matrix<T>& output) const;

    T getThreshold () const;
    void setThreshold (const T& threshold);
  protected:
    T m_threshold;
};

template <typename T>
ThresholdEstimator<T>::ThresholdEstimator ()
{
}

template <typename T>
ThresholdEstimator<T>::~ThresholdEstimator ()
{
}

template <typename T>
void
ThresholdEstimator<T>::compute (const Matrix<T>& input, Matrix<T>& output) const
{
  output.resize (input.getRows (), input.getCols ());

  for (UInt32 i = 0; i < input.getRows (); ++i) {
    for (UInt32 j = 0; j < input.getCols (); ++j) {
      if (input(i,j) < m_threshold) {
        output(i,j) = 0;
      }
    }
  }
}

template <typename T>
T
ThresholdEstimator<T>::getThreshold () const
{
  return m_threshold;
}

template <typename T>
void
ThresholdEstimator<T>::setThreshold (const T& threshold)
{
  m_threshold = threshold;
}

#endif

#endif