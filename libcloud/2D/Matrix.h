#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "../Common/Color.h"
#include <vector>

class Matrix {
  public:
    Matrix (unsigned int rows, unsigned int cols);
    virtual ~Matrix ();
    
    Color& operator() (unsigned int row, unsigned int col);
    const Color& operator() (unsigned int row, unsigned int col) const;
    Color& at (unsigned int row, unsigned int col);
    const Color& at (unsigned int row, unsigned int col) const;

    Color* getData () const;

    unsigned int getRows () const;
    unsigned int getCols () const;

    Matrix getSubMatrix (unsigned int row, unsigned int col, unsigned int height, unsigned int width) const;

    void resize (unsigned int _rows, unsigned int _cols);

    Matrix operator* (double s) const;
    Matrix operator* (const Matrix& m) const;
    

  protected:
    unsigned int rows;
    unsigned int cols;
    std::vector<Color> data;
};

#endif