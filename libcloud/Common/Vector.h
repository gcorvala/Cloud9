#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Point.h"

class Vector : public Point {
  public:
    Vector (const Point& p1 = Point (0, 0, 0), const Point& p2 = Point (0, 0, 0));
    void normalize ();
    double norm () const;
    double norm2 () const;
    Vector operator+ (const Vector& v) const;
    Vector operator- (const Vector& v) const;
    Vector operator* (double s) const;
    Vector operator/ (double s) const;
    Vector operator= (const Vector& v);
    Vector operator+= (const Vector& v);
    Vector operator-= (const Vector& v);
    Vector operator*= (double s);
    Vector operator/= (double s);
    bool operator== (const Vector& v) const;
    bool operator!= (const Vector& v) const;
};

#endif