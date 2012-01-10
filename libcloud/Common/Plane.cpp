#include "Plane.h"

Plane::Plane (const Point& p, const Vector& normal)
{
  a = normal.x;
  b = normal.y;
  c = normal.z;
  Vector p0 = p;
  d = -(normal.dot(p0));
}

Plane::Plane (const Vector& v1, const Vector& v2)
{
}

Plane::Plane (const Point& p1, const Point& p2, const Point& p3)
{
}

Plane::Plane (double a, double b, double c, double d)
{
}

Plane::~Plane ()
{
}


Vector
Plane::getNormal () const
{
  Vector normal;

  Vector p1 (-d/a, 0, 0);
  Vector p2 (0, -d/b, 0);
  Vector p3 (0, 0, -d/c);

  normal = (p2-p1).cross (p3-p1);

  normal.normalize ();

  return normal;
}
