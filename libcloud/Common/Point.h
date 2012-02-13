#ifndef __POINT_H__
#define __POINT_H__

#include "Color.h"

class Point {
  public:
    Point (double _x = 0, double _y = 0, double _z = 0);
    virtual ~Point ();
    Point operator= (const Point& p);
    bool operator== (const Point& p) const;
    bool operator!= (const Point& p) const;
    double x;
    double y;
    double z;
};

#endif