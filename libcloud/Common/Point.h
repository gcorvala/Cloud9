#ifndef __POINT_H__
#define __POINT_H__

#include "Color.h"
#include <iostream>

class Point {
  public:
    typedef Point* ptr;
    typedef const Point* const_ptr;

    Point (Float64 _x = 0, Float64 _y = 0, Float64 _z = 0, const Color& color = Color ());
    virtual ~Point ();
    Point operator= (const Point& p);
    bool operator== (const Point& p) const;
    bool operator!= (const Point& p) const;
    Float64 x;
    Float64 y;
    Float64 z;
    // FIXME : add layer into PointCloud instead of here
    Color m_color;

    friend std::ostream& operator<< (std::ostream& out, const Point& p);
};

#endif