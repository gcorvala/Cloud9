#include "Vector3D.h"

Vector3D::Vector3D (Float32 _x, Float32 _y, Float32 _z)
  :Vector2D (_x, _y)
  ,z (_z)
{
}

Vector3D::Vector3D (const Vector3D& v)
  :Vector2D (v.x, v.y)
  ,z (v.z)
{
}

Vector3D::~Vector3D ()
{
}

Float32
Vector3D::norm2 () const
{
  return Vector2D::norm2 () + z * z;
}

Boolean
Vector3D::operator== (const Vector3D& v) const
{
  return v.x == x && v.y == y && v.z == z;
}

Boolean
Vector3D::operator!= (const Vector3D& v) const
{
  return !(operator== (v));
}

Vector3D&
Vector3D::operator= (const Vector3D& v)
{
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
}

Vector3D
Vector3D::operator+ (const Vector3D& v) const
{
  return Vector3D (v.x + x, v.y + y, v.z + z);
}

Vector3D
Vector3D::operator- (const Vector3D& v) const
{
  return Vector3D (v.x - x, v.y - y, v.z - z);
}

/*Vector3D operator* (Float32 s) const;
Vector3D operator/ (Float32 s) const;*/

Float32
Vector3D::distanceTo (const Vector3D& v) const
{
  std::cout << "Vector3D" << std::endl;
  return (*this - v).norm ();
}