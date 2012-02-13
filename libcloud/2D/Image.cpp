#include "Image.h"

Image::Image (UInt32 rows, UInt32 cols)
  :rows(rows)
  ,cols(cols)
  ,red_channel(rows, cols)
  ,green_channel(rows, cols)
  ,blue_channel(rows, cols)
{
}

Image::~Image ()
{
}

Color
Image::getPixel (UInt32 row, UInt32 col) const
{
  return Color (red_channel(row,col), green_channel(row,col), blue_channel(row,col));
}

void
Image::setPixel (UInt32 row, UInt32 col, const Color c)
{
  red_channel(row,col) = c.r;
  green_channel(row,col) = c.g;
  blue_channel(row,col) = c.b;
}

unsigned int
Image::getRows () const
{
  return rows;
}

unsigned int
Image::getCols () const
{
  return cols;
}

void
Image::resize (UInt32 _rows, UInt32 _cols)
{
  rows = _rows;
  cols = _cols;
  red_channel.resize (_rows, _cols);
  green_channel.resize (_rows, _cols);
  blue_channel.resize (_rows, _cols);
}

Matrix<UInt8>&
Image::getRedChannel ()
{
  return red_channel;
}

Matrix<UInt8>&
Image::getGreenChannel ()
{
  return green_channel;
}

Matrix<UInt8>&
Image::getBlueChannel ()
{
  return blue_channel;
}

Matrix<UInt8>
Image::getYChannel () const
{
  Matrix<UInt8> result (rows, cols);

  for (UInt32 i = 0; i < rows; ++i) {
    for (UInt32 j = 0; j < cols; ++j) {
      result (i, j) = getPixel (i, j).getY ();
    }
  }

  return result;
}