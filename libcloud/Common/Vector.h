#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Point.h"

class Vector : public Point {
  public:
    Vector (Float64 _x = 0, Float64 _y = 0, Float64 _z = 0);
    Vector (const Point& p1, const Point& p2 = Point (0, 0, 0));

    void normalize ();
    Vector normalized () const;
    Float64 norm () const;
    Float64 norm2 () const;

    Vector operator+ (const Vector& v) const;
    Vector operator- (const Vector& v) const;
    Vector operator* (Float64 s) const;
    Vector operator/ (Float64 s) const;
    Vector operator+= (const Vector& v);
    Vector operator-= (const Vector& v);
    Vector operator*= (Float64 s);
    Vector operator/= (Float64 s);
    Vector operator- () const;

    Vector cross (const Vector& v) const;
    Float64 dot (const Vector& v) const;

    Float64 angle (const Vector& v) const;
};

#endif