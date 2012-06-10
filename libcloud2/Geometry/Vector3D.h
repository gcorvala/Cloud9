#ifndef __VECTOR_3D_H__
#define __VECTOR_3D_H__

#include "Vector2D.h"

class Vector3D : public Vector2D {
  public:
    Vector3D (Float32 _x = 0, Float32 _y = 0, Float32 _z = 0);
    Vector3D (const Vector3D& v);
    virtual ~Vector3D ();

    Float32 norm2 () const;

    Boolean operator== (const Vector3D& v) const;
    Boolean operator!= (const Vector3D& v) const;

    Vector3D& operator= (const Vector3D& v);

    Vector3D operator+ (const Vector3D& v) const;
    Vector3D operator- (const Vector3D& v) const;

    //Vector3D operator* (Float32 s) const;
    //Vector3D operator/ (Float32 s) const;

    Float32 distanceTo (const Vector3D& v) const;

    Float32 z;
};

#endif