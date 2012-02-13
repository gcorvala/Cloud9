#include "ImageDrawer.h"

ImageDrawer::ImageDrawer (UInt32 rows, UInt32 cols, const Color& color)
  :image(rows, cols)
{
  fill (color);
}

ImageDrawer::~ImageDrawer ()
{
}

void
ImageDrawer::fill (const Color& color)
{
  for (UInt32 i = 0; i < image.getRows (); ++i) {
    for (UInt32 j = 0; j < image.getCols (); ++j) {
      image.setPixel (i, j, color);
    }
  }
}

void
ImageDrawer::drawPoint (const Point& point, const Color& color)
{
  if (point.x >= 0 && point.y >= 0 && point.x < image.getCols () && point.y < image.getRows ()) {
    image.setPixel (point.y, point.x, color);
  }
}

void
ImageDrawer::drawLine (const Line& line, const Color& color)
{
  for (UInt32 i = 0; i < image.getCols (); ++i) {
    drawPoint (Point (i, line.getYValue (i)), color);
  }
}

Image
ImageDrawer::getImage () const
{
  return image;
}

void
ImageDrawer::setImage (const Image& im)
{
  image = im;
}