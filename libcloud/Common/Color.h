#ifndef __COLOR_H__
#define __COLOR_H__

#include "Types.h"

class Color {
  public:
    Color ();
    Color (UInt8 gray);
    Color (UInt8 _r, UInt8 _g, UInt8 _b);
    virtual ~Color ();

    Color operator* (double s) const;
    Color operator* (const Color c) const;
    Color operator+= (const Color c);

    UInt8 getR () const;
    UInt8 getG () const;
    UInt8 getB () const;
    UInt8 getY () const;
    UInt8 getU () const;
    UInt8 getV () const;

    UInt8 r;
    UInt8 g;
    UInt8 b;
};

#endif