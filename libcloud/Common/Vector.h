#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Point.h"

class Vector : public Point {
  public:
    Vector (double _x = 0, double _y = 0, double _z = 0);
    Vector (const Point& p1, const Point& p2 = Point (0, 0, 0));

    void normalize ();
    double norm () const;
    double norm2 () const;

    Vector operator+ (const Vector& v) const;
    Vector operator- (const Vector& v) const;
    Vector operator* (double s) const;
    Vector operator/ (double s) const;
    Vector operator+= (const Vector& v);
    Vector operator-= (const Vector& v);
    Vector operator*= (double s);
    Vector operator/= (double s);
    Vector operator- () const;

    Vector cross (const Vector& v) const;
    double dot (const Vector& v) const;
};

#endif