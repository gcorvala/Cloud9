#include "Point3D.h"

#if 0
#include <math.h>

Point3D::Point3D (Float32 _x, Float32 _y, Float32 _z)
  :x (_x)
  ,y (_y)
  ,z (_z)
{
}

Point3D::~Point3D ()
{
}

virtual Boolean operator== (const Point2D& p) const;
virtual Boolean operator!= (const Point2D& p) const;

virtual Point2D& operator= (const Point2D& p);

virtual Point2D operator+ (const Point2D& p) const;
virtual Point2D operator- (const Point2D& p) const;
virtual Point2D& operator+= (const Point2D& p);
virtual Point2D& operator-= (const Point2D& p);

virtual Point2D operator* (Float32 s) const;
virtual Point2D operator/ (Float32 s) const;
virtual Point2D& operator*= (Float32 s);
virtual Point2D& operator/= (Float32 s);

Float64 distanceTo (const Point3D& p) const;
#endif