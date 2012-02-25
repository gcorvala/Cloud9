#include "Plane.h"

#include <math.h>
#include <stdlib.h>

Plane::Plane ()
  :a(1)
  ,b(0)
  ,c(0)
  ,d(0)
{
}

Plane::Plane (const Point& p1, const Point& p2, const Point& p3)
{
  Vector v1 (p2, p1);
  Vector v2 (p3, p1);
  Vector normal = v1.cross (v2);

  a = normal.x;
  b = normal.y;
  c = normal.z;

  d = -normal.dot (p1);
}

Plane::Plane (Float64 _a, Float64 _b, Float64 _c, Float64 _d)
  :a(_a)
  ,b(_b)
  ,c(_c)
  ,d(_d)
{
}

Plane::Plane (Float64 rho, Float64 theta, Float64 phi)
  :a(cos (theta)*sin (phi))
  ,b(sin (phi)*sin (theta))
  ,c(cos (phi))
  ,d(-rho)
{
}

Plane::~Plane ()
{
}

Vector
Plane::getNormal () const
{
  Float64 t = sqrt (a*a+b*b+c*c);
  return Vector (a/t, b/t, c/t);
}

Float64
Plane::getRho () const
{
  return abs (d)/sqrt (a*a+b*b+c*c);
}

Float64
Plane::getTheta () const
{
  Float64 theta;

  theta = atan2 (b, a);
  if (theta < 0) {
    theta += 2.*M_PI;
  }

  return theta;
}

Float64
Plane::getPhi () const
{
  Float64 phi;

  phi = atan2 (hypot (a, b), c);
  if (phi < 0) {
    phi += 2.*M_PI;
  }
  
  return phi;
}