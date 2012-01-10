#ifndef __PLANE_H__
#define __PLANE_H__

#include "Point.h"
#include "Vector.h"

class Plane {
  public:
    Plane (const Point& p, const Vector& normal);
    Plane (const Vector& v1, const Vector& v2);
    Plane (const Point& p1, const Point& p2, const Point& p3);
    Plane (double a, double b, double c, double d);
    virtual ~Plane ();
  protected:
    // FIXME : Forme ax+by+cz+d=0
    double a;
    double b;
    double c;
};

#endif