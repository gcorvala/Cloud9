#ifndef __HOUGH_ESTIMATOR_H__
#define __HOUGH_ESTIMATOR_H__

#include "Estimator.h"
#include "Matrix.h"
#include "Line.h"
#include "../Common/Vector.h"
#include "../Common/PointCloud.h"

class HoughEstimator : public Estimator<UInt8, UInt32> {
  public:
    HoughEstimator ();
    ~HoughEstimator ();
    void compute (const Matrix<UInt8>& input, Matrix<UInt32>& output) const;
    void compute (const PointCloud& cloud, Matrix<UInt32>& output) const;

    UInt32 getNTheta () const;
    void setNTheta (UInt32 n);

    UInt32 getNRho () const;
    void setNRho (UInt32 n);

    Float64 getThetaStep () const;
    Float64 getRhoStep (const Matrix<UInt8>& input) const;
    Float64 getRhoStep (const PointCloud& cloud) const;
  protected:
    UInt32 n_theta;
    UInt32 n_rho;
};

template <typename T>
class Accumulator : public Matrix <T> {
  public:
    Accumulator (UInt32 rows = 0, UInt32 cols = 0);

    T& operator() (UInt32 row, UInt32 col);
    const T& operator() (UInt32 row, UInt32 col) const;
    T& at (UInt32 row, UInt32 col);
    const T& at (UInt32 row, UInt32 col) const;

  protected:
};

template <typename T>
Accumulator<T>::Accumulator (UInt32 rows, UInt32 cols)
  :Matrix<T>(rows, cols)
{
}

template <typename T>
T&
Accumulator<T>::operator() (UInt32 row, UInt32 col)
{
  return Matrix<T>::operator() (row%Matrix<T>::rows,col%Matrix<T>::cols);
}

template <typename T>
const T&
Accumulator<T>::operator() (UInt32 row, UInt32 col) const
{
  return Matrix<T>::operator() (row%Matrix<T>::rows,col%Matrix<T>::cols);
}

template <typename T>
T&
Accumulator<T>::at (UInt32 row, UInt32 col)
{
  return Matrix<T>::operator() (row%Matrix<T>::rows,col%Matrix<T>::cols);
}

template <typename T>
const T&
Accumulator<T>::at (UInt32 row, UInt32 col) const
{
  return Matrix<T>::operator() (row%Matrix<T>::rows,col%Matrix<T>::cols);
}

#endif
