#include "Plane.h"

Plane::Plane (const Point& p, const Vector& normal)
{
  a = normal.x;
  b = normal.y;
  c = normal.z;
  Vector v = p;
  d = -normal.dot(v);
}

Plane::Plane (const Vector& v1, const Vector& v2, const Point& p)
{
  Vector normal = v1.cross (v2);

  a = normal.x;
  b = normal.y;
  c = normal.z;

  Vector v = p;

  d = -normal.dot (v);
}

Plane::Plane (const Point& p1, const Point& p2, const Point& p3)
{
  Vector v1 = Vector (p2)-Vector (p1);
  Vector v2 = Vector (p3)-Vector (p1);
  Vector normal = v1.cross (v2);

  a = normal.x;
  b = normal.y;
  c = normal.z;

  Vector v = p1;

  d = -normal.dot (v);
}

Plane::Plane (double _a, double _b, double _c, double _d)
  :a(_a)
  ,b(_b)
  ,c(_c)
  ,d(_d)
{
}

Plane::~Plane ()
{
}


Vector
Plane::getNormal () const
{
  Vector normal;

  // FIXME : error if a,b or c = 0

  Vector p1 (-d/a, 0, 0);
  Vector p2 (0, -d/b, 0);
  Vector p3 (0, 0, -d/c);

  normal = (p2-p1).cross (p3-p1);

  normal.normalize ();

  return normal;
}
