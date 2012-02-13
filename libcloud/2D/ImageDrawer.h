#ifndef __IMAGE_DRAWER_H__
#define __IMAGE_DRAWER_H__

#include "Image.h"
#include "Line.h"
#include "../Common/Point.h"

class ImageDrawer {
  public:
    ImageDrawer (UInt32 rows, UInt32 cols, const Color& color = Color ());
    virtual ~ImageDrawer ();

    void fill (const Color& color);

    void drawPoint (const Point& point, const Color& color = Color (255, 255, 255));
    void drawLine (const Line& line, const Color& color = Color (255, 255, 255));

    Image getImage () const;
    void setImage (const Image& im);

  protected:
    Image image;
};

#endif