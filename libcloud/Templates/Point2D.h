#ifndef __POINT_2D_H__
#define __POINT_2D_H__

template <typename T>
class Point2D {
  public:
    Point2D (const T& x_, const T& y_);
    Point2D (const Point2D& p);
    virtual ~Point2D ();

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

#endif