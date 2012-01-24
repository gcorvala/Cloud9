#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "Matrix.h"
#include "../Common/Color.h"

class Image {
  public:
    Image (UInt32 rows = 0, UInt32 cols = 0);
    virtual ~Image ();

    // FIXME : replace by operator()
    Color getPixel (UInt32 row, UInt32 col) const;
    void setPixel (UInt32 row, UInt32 col, const Color c);

    unsigned int getRows () const;
    unsigned int getCols () const;

    void resize (UInt32 _rows, UInt32 _cols);

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