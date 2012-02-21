#ifndef __PLANE_H__
#define __PLANE_H__

#include "Point.h"
#include "Vector.h"

class Plane {
  public:
    Plane ();
    Plane (const Point& p, const Vector& normal);
    Plane (const Point& p1, const Point& p2, const Point& p3);
    Plane (Float64 _a, Float64 _b, Float64 _c, Float64 _d);
    Plane (Float64 rho, Float64 theta, Float64 phi);
    virtual ~Plane ();

    Vector getNormal () const;
    Float64 getRho () const;
    Float64 getTheta () const;
    Float64 getPhi () const;

  protected:
#if 0
    // FIXME : Forme ax+by+cz+d=0
    Float64 a;
    Float64 b;
    Float64 c;
    Float64 d;
#else
    // FIXME : Forme n.x*x+n.y*y+n.z*z=1
    Vector n;
#endif
};

#endif