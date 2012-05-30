#ifndef __BOX_2D_H__
#define __BOX_2D_H__

#include "Point2D.h"

class Box2D {
  public:
    Box2D (const Point2D& p1, const Point2D& p2);
    virtual ~Box2D ();

    Point2D getMin () const;
    Point2D getMax () const;

  protected:
    Point2D m_min;
    Point2D m_max;
};

#endif