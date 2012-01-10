#ifndef __PLANE_H__
#define __PLANE_H__

#include "Point.h"
#include "Vector.h"

class Plane {
  public:
    Plane (const Point& p, const Vector& normal);
    Plane (const Vector& v1, const Vector& v2, const Point& p);
    Plane (const Point& p1, const Point& p2, const Point& p3);
    Plane (double _a = 0, double _b = 0, double _c = 0, double _d = 0);
    virtual ~Plane ();

    Vector getNormal () const;

  protected:
    // FIXME : Forme ax+by+cz+d=0
    double a;
    double b;
    double c;
    double d;
};

#endif