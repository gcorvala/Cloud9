#ifndef __POINT_2D_H__
#define __POINT_2D_H__

#if 0
#include "../Common/Types.h"

class Point2D {
  public:
    typedef Point2D* ptr;
    typedef const Point2D* const_ptr;

    Point2D (Float32 _x = 0, Float32 _y = 0);
    Point2D (const Point2D& p);
    virtual ~Point2D ();

    Float32 norm () const;
    virtual Float32 norm2 () const;
    void normalize ();
    Point2D normalized () const;

    virtual Boolean operator== (const Point2D& p) const;
    Boolean operator!= (const Point2D& p) const;

    virtual Point2D& operator= (const Point2D& p);

    virtual Point2D operator+ (const Point2D& p) const;
    virtual Point2D operator- (const Point2D& p) const;
    virtual Point2D& operator+= (const Point2D& p);
    virtual Point2D& operator-= (const Point2D& p);

    virtual Point2D operator* (Float32 s) const;
    virtual Point2D operator/ (Float32 s) const;
    virtual Point2D& operator*= (Float32 s);
    virtual Point2D& operator/= (Float32 s);

    virtual Float64 distanceTo (const Point2D& p) const;

    Float32 x, y;
};

#else

#include "Vector2D.h"

typedef Vector2D Point2D;

#endif

#endif