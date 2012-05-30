#ifndef __POINT_3D_H__
#define __POINT_3D_H__

#if 0
#include "Point2D.h"

class Point3D : public Point2D {
  public:
    typedef Point3D* ptr;
    typedef const Point3D* const_ptr;

    Point3D (Float32 _x = 0, Float32 _y = 0, Float32 _z = 0);
    virtual ~Point3D ();

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
    
    Float32 z;
};

#else
#include "Vector3D.h"

typedef Vector3D Point3D;

#endif

#endif