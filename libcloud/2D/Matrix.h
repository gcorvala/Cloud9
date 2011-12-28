#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream> // FIXME
#include "../Common/Types.h"

template <typename T>
class Matrix {
  public:
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    Matrix (UInt32 rows, UInt32 cols);
    virtual ~Matrix ();

    T& operator() (UInt32 row, UInt32 col);
    const T& operator() (UInt32 row, UInt32 col) const;
    T& at (UInt32 row, UInt32 col);
    const T& at (UInt32 row, UInt32 col) const;

    T* getData () const;

    iterator begin ();
    const_iterator begin () const;
    iterator end ();
    const_iterator end () const;

    UInt32 getRows () const;
    UInt32 getCols () const;

    Matrix getSubMatrix (UInt32 row, UInt32 col, UInt32 height, UInt32 width) const;

    void resize (UInt32 _rows, UInt32 _cols);

    Matrix operator* (double s) const;

    Matrix operator* (const Matrix& m) const;

    template <typename U, typename V>
    Matrix<U> convolve (const Matrix<V>& kernel) const;

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
  return data[row*cols+col];
}

template <typename T>
const T&
Matrix<T>::operator() (UInt32 row, UInt32 col) const
{
  return data[row*cols+col];
}

template <typename T>
T&
Matrix<T>::at (UInt32 row, UInt32 col)
{
  return data[row*cols+col];
}

template <typename T>
const T&
Matrix<T>::at (UInt32 row, UInt32 col) const
{
  return data[row*cols+col];
}

template <typename T>
T*
Matrix<T>::getData () const
{
  UInt8* result = new T[rows*cols];

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
Matrix<T>
Matrix<T>::operator* (double s) const
{
  Matrix<T> result (rows, cols);

  for (UInt32 i = 0; i <= rows*cols; ++i) {
    result.data[i] *= s;
  }

  return result;
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
template <typename U, typename V>
Matrix<U>
Matrix<T>::convolve (const Matrix<V>& kernel) const
{
  Matrix<U> result (rows, cols);

  for (UInt32 m = 0; m < cols; ++m) {
    for (UInt32 n = 0; n < rows; ++n) {
      result(m,n) = 0;
      for (UInt32 j = 0; j < cols; ++j) {
        for (UInt32 i = 0; i < rows; ++i) {
          result(m,n) += at(i,j)*kernel(m-i,n-j);
          std::cout << "at = " << at(i,j) << std::endl;
          std::cout << "kernel = " << (unsigned int) kernel(m-i,n-j) << std::endl;
          std::cout << "result = " << result(m,n) << std::endl;
        }
      }
    }
  }

  return result;
}
#endif