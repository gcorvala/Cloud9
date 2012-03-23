#ifndef __POINT_3D_H__
#define __POINT_3D_H__

template <typename T>
class Point3D {
  public:
    Point3D (const T& x_ = T (), const T& y_ = T (), const T& z_ = T ());
    Point3D (const Point3D& p);
    virtual ~Point3D ();

    bool operator== (const Point3D& p) const;

    Float64 distanceTo (const Point3D& p) const;

    T x;
    T y;
    T z;
};

template <typename T>
Point3D <T>::Point3D (const T& x_, const T& y_, const T& z_)
  :x (x_)
  ,y (y_)
  ,z (z_)
{
}

template <typename T>
Point3D<T>::Point3D (const Point3D& p)
  :x (p.x)
  ,y (p.y)
  ,z (p.z)
{
}

template <typename T>
Point3D <T>::~Point3D ()
{
}

#endif