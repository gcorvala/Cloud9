#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include "../Common/Types.h"

class Vector2D {
  public:
    typedef Vector2D* ptr;
    typedef const Vector2D* const_ptr;

    Vector2D (Float32 _x = 0, Float32 _y = 0);
    Vector2D (const Vector2D& v);
    virtual ~Vector2D ();
    
    Float32 norm () const;
    Float32 norm2 () const;
    void normalize ();
    Vector2D normalized () const;

    Boolean operator== (const Vector2D& v) const;
    Boolean operator!= (const Vector2D& v) const;

    Vector2D& operator= (const Vector2D& v);

    Vector2D operator+ (const Vector2D& v) const;
    Vector2D operator- (const Vector2D& v) const;
    Vector2D& operator+= (const Vector2D& v);
    Vector2D& operator-= (const Vector2D& v);

    Vector2D operator* (Float32 s) const;
    Vector2D operator/ (Float32 s) const;
    Vector2D& operator*= (Float32 s);
    Vector2D& operator/= (Float32 s);

    Float32 x;
    Float32 y;
};

#endif