#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "Matrix.h"
#include "../Common/Color.h"

class Image {
  public:
    Image (unsigned int rows, unsigned int cols);
    virtual ~Image ();

    Color getPixel (unsigned int row, unsigned int col) const;
    void setPixel (unsigned int row, unsigned int col, const Color c);

    unsigned int getRows () const;
    unsigned int getCols () const;

    void resize (unsigned int _rows, unsigned int _cols);

    Matrix<UInt8>& getRedChannel ();
    Matrix<UInt8>& getGreenChannel ();
    Matrix<UInt8>& getBlueChannel ();
    Matrix<UInt8> getYChannel () const;

  protected:
    unsigned int rows;
    unsigned int cols;

    Matrix<UInt8> red_channel;
    Matrix<UInt8> green_channel;
    Matrix<UInt8> blue_channel;
};

#endif