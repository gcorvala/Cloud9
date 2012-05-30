#ifndef __BOX_3D_H__
#define __BOX_3D_H__

#include "Point3D.h"

class Box3D {
  public:
    Box3D (const Point3D& p1 = Point3D (), const Point3D& p2 = Point3D ());
    virtual ~Box3D ();

    Point3D getMin () const;
    Point3D getMax () const;

    Float32 getDiagonalLength () const;

  protected:
    Point3D m_min;
    Point3D m_max;
};

#endif