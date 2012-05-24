#ifndef __POINT_H__
#define __POINT_H__

#include "../Common/Types.h"

class Point {
  public:
    typedef Point* ptr;
    typedef const Point* const_ptr;

    Point (Float32 _x = 0, Float32 _y = 0, Float32 _z = 0);
    virtual ~Point ();
    
    Float64 distanceTo (const Point& p) const;
    Point& operator= (const Point& p);
    
    Float32 x, y, z;
};

#endif