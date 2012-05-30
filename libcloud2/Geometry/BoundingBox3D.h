#ifndef __BOUNDING_BOX_3D_H__
#define __BOUNDING_BOX_3D_H__

#include "Box3D.h"

class BoundingBox3D : public Box3D {
  public:
    BoundingBox3D ();
    virtual ~BoundingBox3D ();

    void add (const Point3D& p);
};

#endif