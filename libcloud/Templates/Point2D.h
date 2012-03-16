#ifndef __POINT_2D_H__
#define __POINT_2D_H__

#include "../Common/Types.h"
#include <math.h>

template <typename T>
class Point2D {
  public:
    Point2D (const T& x_ = T (), const T& y_ = T ());
    Point2D (const Point2D& p);
    virtual ~Point2D ();

    bool operator== (const Point2D <T>& p) const;

    Float64 distanceTo (const Point2D <T>& p) const;

    T x;
    T y;
};

template <typename T>
Point2D <T>::Point2D (const T& x_, const T& y_)
  :x (x_)
  ,y (y_)
{
}

template <typename T>
Point2D<T>::Point2D (const Point2D& p)
  :x (p.x)
  ,y (p.y)
{
}

template <typename T>
Point2D <T>::~Point2D ()
{
}

template <typename T>
bool
Point2D <T>::operator== (const Point2D <T>& p) const
{
  return (x == p.x) && (y == p.y);
}

#include <iostream>

template <typename T>
Float64
Point2D <T>::distanceTo (const Point2D <T>& p) const
{
  return hypot (p.x-x, p.y-y);
}

#endif