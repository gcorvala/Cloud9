#include "Matrix.h"

#include <algorithm>

Matrix::Matrix (unsigned int rows, unsigned int cols)
  :rows(rows)
  ,cols(cols)
  ,data(rows*cols)
{
  //data = new bool[rows*cols];
  //data.reserve (rows*cols);
}

Matrix::~Matrix ()
{
//  delete [] data;
}

Color&
Matrix::operator() (unsigned int row, unsigned int col)
{
  return data[row*cols+col];
}

const Color&
Matrix::operator() (unsigned int row, unsigned int col) const
{
  return data[row*cols+col];
}

Color&
Matrix::at (unsigned int row, unsigned int col)
{
  return data[row*cols+col];
}

const Color&
Matrix::at (unsigned int row, unsigned int col) const
{
  return data[row*cols+col];
}

Color*
Matrix::getData () const
{
  Color* result = new Color[rows*cols];

  for (unsigned int i = 0; i < rows*cols; ++i) {
    result[i] = data[i];
  }

  return result;
}

unsigned int
Matrix::getRows () const
{
  return rows;
}

unsigned int
Matrix::getCols () const
{
  return cols;
}

Matrix
Matrix::getSubMatrix (unsigned int row, unsigned int col, unsigned int height, unsigned int width) const
{
  Matrix *sub_matrix = new Matrix (height, width);
  for (unsigned int i = 0; i < height; ++i) {
    for (unsigned int j = 0; j < width; ++j) {
      sub_matrix->at (i, j) = at (row+i, col+i); 
    }
  }
  return *sub_matrix;
}

void
Matrix::resize (unsigned int _rows, unsigned int _cols)
{
  rows = _rows;
  cols = _cols;
  data.resize (rows*cols);
}

Matrix
Matrix::operator* (double s) const
{
  Matrix result (rows, cols);
  
  for (unsigned int i = 0; i <= rows*cols; ++i) {
    result.data[i] = Color (data[i].r*s, data[i].g*s, data[i].b*s);
  }

  return result;
}

Matrix
Matrix::operator* (const Matrix& m) const
{
  Matrix result (rows, m.cols);

  for (unsigned int i = 0; i < result.rows; ++i) {
    for (unsigned int j = 0; j < result.cols; ++j) {
      for (unsigned int k = 0; k < cols; ++k) {
        result(i, j) += at (i, k)*m(k, j);
      }
    }
  }

  return result;
}
