#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream> // FIXME
#include <math.h>
#include "../Common/Types.h"

template <typename T>
class Matrix {
  public:
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    Matrix (UInt32 rows = 0, UInt32 cols = 0);
    virtual ~Matrix ();

    T& operator() (UInt32 row, UInt32 col);
    const T& operator() (UInt32 row, UInt32 col) const;
    T& at (UInt32 row, UInt32 col);
    const T& at (UInt32 row, UInt32 col) const;

    T* getData () const;

    void fill (const T& value);

    iterator begin ();
    const_iterator begin () const;
    iterator end ();
    const_iterator end () const;

    UInt32 getRows () const;
    UInt32 getCols () const;

    void resize (UInt32 _rows, UInt32 _cols);

    Matrix getSubMatrix (UInt32 row, UInt32 col, UInt32 height, UInt32 width) const;

    template <typename U>
    Matrix<T> operator= (const Matrix<U>& m);
    Matrix operator* (double s) const;
    Matrix operator*= (double s);
    Matrix operator/ (double s) const;
    Matrix operator/= (double s);
    Matrix operator* (const Matrix& m) const;
    template <typename U>
    Matrix operator+ (const Matrix<U>& m) const;

    template <typename KernelType, typename OutputType>
    void convolve (const Matrix<KernelType>& kernel, Matrix<OutputType>& output) const;

    template <typename InputType, typename OutputType>
    void mul (const Matrix<InputType>& m, Matrix<OutputType>& output) const;

    template <typename U>
    void sqrt (Matrix<U>& output) const;

    T max () const;
    T max (UInt32& row, UInt32& col) const;

  protected:
    UInt32 rows;
    UInt32 cols;
    std::vector<T> data;
};

template <typename T>
Matrix<T>::Matrix (UInt32 rows, UInt32 cols)
  :rows(rows)
  ,cols(cols)
  ,data(rows*cols)
{
}

template <typename T>
Matrix<T>::~Matrix ()
{
}

template <typename T>
T&
Matrix<T>::operator() (UInt32 row, UInt32 col)
{
  if (row < 0 || col < 0) exit (0);
  return data[row*cols+col];
}

template <typename T>
const T&
Matrix<T>::operator() (UInt32 row, UInt32 col) const
{
  if (row < 0 || col < 0) exit (0);
  return data[row*cols+col];
}

template <typename T>
T&
Matrix<T>::at (UInt32 row, UInt32 col)
{
  if (row < 0 || col < 0) exit (0);
  return data[row*cols+col];
}

template <typename T>
const T&
Matrix<T>::at (UInt32 row, UInt32 col) const
{
  if (row < 0 || col < 0) exit (0);
  return data[row*cols+col];
}

template <typename T>
void
Matrix<T>::fill (const T& value)
{
  for (UInt32 i = 0; i < rows*cols; ++i) {
    data[i] = value;
  }
}


template <typename T>
T*
Matrix<T>::getData () const
{
  T* result = new T[rows*cols];

  for (UInt32 i = 0; i < rows*cols; ++i) {
    result[i] = data[i];
  }

  return result;
}

template <typename T>
typename Matrix<T>::iterator
Matrix<T>::begin ()
{
  return data.begin ();
}

template <typename T>
typename Matrix<T>::const_iterator
Matrix<T>::begin () const
{
  return data.begin ();
}

template <typename T>
typename Matrix<T>::iterator
Matrix<T>::end ()
{
  return data.end ();
}

template <typename T>
typename Matrix<T>::const_iterator
Matrix<T>::end () const
{
  return data.end ();
}

template <typename T>
UInt32
Matrix<T>::getRows () const
{
  return rows;
}

template <typename T>
UInt32
Matrix<T>::getCols () const
{
  return cols;
}

template <typename T>
Matrix<T>
Matrix<T>::getSubMatrix (UInt32 row, UInt32 col, UInt32 height, UInt32 width) const
{
  Matrix<T> *sub_matrix = new Matrix (height, width);

  for (UInt32 i = 0; i < height; ++i) {
    for (UInt32 j = 0; j < width; ++j) {
      sub_matrix->at (i, j) = at (row+i, col+i);
    }
  }

  return *sub_matrix;
}

template <typename T>
void
Matrix<T>::resize (UInt32 _rows, UInt32 _cols)
{
  rows = _rows;
  cols = _cols;
  data.resize (rows*cols);
}

template <typename T>
template <typename U>
Matrix<T>
Matrix<T>::operator= (const Matrix<U>& m)
{
  rows = m.getRows ();
  cols = m.getCols ();
  data.resize (rows*cols);
  for (UInt32 i = 0; i < rows; ++i) {
    for (UInt32 j = 0; j < cols; ++j) {
      at(i,j) = m(i,j);
    }
  }

  return *this;
}


template <typename T>
Matrix<T>
Matrix<T>::operator* (double s) const
{
  Matrix<T> result (rows, cols);

  for (UInt32 i = 0; i < rows*cols; ++i) {
    result.data[i] = data[i]*s;
  }

  return result;
}

template <typename T>
Matrix<T>
Matrix<T>::operator*= (double s)
{
  for (UInt32 i = 0; i < rows*cols; ++i) {
    data[i] *= s;
  }

  return *this;
}

template <typename T>
Matrix<T>
Matrix<T>::operator/ (double s) const
{
  Matrix<T> result (rows, cols);

  for (UInt32 i = 0; i < rows*cols; ++i) {
    result.data[i] = data[i]/s;
  }

  return result;
}

template <typename T>
Matrix<T>
Matrix<T>::operator/= (double s)
{
  for (UInt32 i = 0; i < rows*cols; ++i) {
    data[i] /= s;
  }

  return *this;
}

template <typename T>
Matrix<T>
Matrix<T>::operator* (const Matrix& m) const
{
  Matrix<T> result (rows, m.cols);

  for (UInt32 i = 0; i < result.rows; ++i) {
    for (UInt32 j = 0; j < result.cols; ++j) {
      for (UInt32 k = 0; k < cols; ++k) {
        result(i, j) += at (i, k)*m(k, j);
      }
    }
  }

  return result;
}

template <typename T>
template <typename U>
Matrix<T>
Matrix<T>::operator+ (const Matrix<U>& m) const
{
  Matrix<T> result (rows, cols);

  for (UInt32 i = 0; i < result.rows; ++i) {
    for (UInt32 j = 0; j < result.cols; ++j) {
      result(i,j) = at(i,j)+m(i,j);
    }
  }

  return result;
}

template <typename T>
template <typename KernelType, typename OutputType>
void
Matrix<T>::convolve (const Matrix<KernelType>& kernel, Matrix<OutputType>& output) const
{
  output.resize (rows, cols);

  UInt32 kernel_center_x = kernel.getCols () / 2;
  UInt32 kernel_center_y = kernel.getRows () / 2;

  for (UInt32 i = 0; i < rows; ++i) {
    for (UInt32 j = 0; j < cols; ++j) {
      output(i,j) = 0;
      for (UInt32 m = 0; m < kernel.getRows (); ++m) {
        UInt32 mm = kernel.getRows ()-1-m;
        for (UInt32 n = 0; n < kernel.getCols (); ++n) {
          UInt32 nn = kernel.getCols ()-1-n;
          UInt32 ii = i+(m-kernel_center_y);
          UInt32 jj = j+(n-kernel_center_x);
          if (ii >= 0 && ii < rows && jj >= 0 && jj < cols)
            output(i,j) += at(ii,jj)*kernel(mm,nn);
        }
      }
    }
  }
}

template <typename T>
template <typename InputType, typename OutputType>
void
Matrix<T>::mul (const Matrix<InputType>& m, Matrix<OutputType>& output) const
{
  // FIXME : check sizes !
  output.resize (rows, cols);
  for (UInt32 i = 0; i < rows; ++i) {
    for (UInt32 j = 0; j < cols; ++j) {
      output(i,j) = at(i,j)*m(i,j);
    }
  }
}

template <typename T>
template <typename U>
void
Matrix<T>::sqrt (Matrix<U>& output) const
{
  output.resize (rows, cols);
  for (UInt32 i = 0; i < rows; ++i) {
    for (UInt32 j = 0; j < cols; ++j) {
      output(i,j) = ::sqrt (at(i,j));
    }
  }
}

template <typename T>
T
Matrix<T>::max () const
{
  return *max_element (data.begin (), data.end ());
}

template <typename T>
T
Matrix<T>::max (UInt32& row, UInt32& col) const
{
  const_iterator max = max_element (data.begin (), data.end ());

  UInt32 idx = std::distance (data.begin (), max);

  row = idx/cols;
  col = idx%cols;

  return *max;
}

#endif