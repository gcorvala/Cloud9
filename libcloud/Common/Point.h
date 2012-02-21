#ifndef __POINT_H__
#define __POINT_H__

#include "Color.h"

class Point {
  public:
    Point (Float64 _x = 0, Float64 _y = 0, Float64 _z = 0);
    virtual ~Point ();
    Point operator= (const Point& p);
    bool operator== (const Point& p) const;
    bool operator!= (const Point& p) const;
    Float64 x;
    Float64 y;
    Float64 z;
};

#endif