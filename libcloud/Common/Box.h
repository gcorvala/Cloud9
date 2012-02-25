#ifndef __BOX_H__
#define __BOX_H__

#include "Types.h"
#include "Point.h"

class Box {
  public:
    Box (const Point& min, const Point& max);
    virtual ~Box ();

    Point getMin () const;
    void setMin (const Point& min);

    Point getMax () const;
    void setMax (const Point& max);

    Point getCenter () const;

    Float64 getWidth () const;
    Float64 getHeight () const;
    Float64 getDepth () const;

  private:
    Point m_min;
    Point m_max;
};

#endif