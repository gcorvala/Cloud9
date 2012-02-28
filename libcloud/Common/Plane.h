#ifndef __PLANE_H__
#define __PLANE_H__

#include "Point.h"
#include "Vector.h"

class Plane {
  public:
    Plane ();
    Plane (const Point& p1, const Point& p2, const Point& p3);
    Plane (Float64 _a, Float64 _b, Float64 _c, Float64 _d);
    explicit Plane (Float64 rho, Float64 theta, Float64 phi);
    virtual ~Plane ();

    Vector getNormal () const;
    Float64 getRho () const;
    Float64 getTheta () const;
    Float64 getPhi () const;

    Float64 getXValue (Float64 y, Float64 z) const;
    Float64 getYValue (Float64 x, Float64 z) const;
    Float64 getZValue (Float64 x, Float64 y) const;

  protected:
    // FIXME : Forme ax+by+cz+d=0
    Float64 a;
    Float64 b;
    Float64 c;
    Float64 d;
};

#endif