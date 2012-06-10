#ifndef __LINE_2D_H__
#define __LINE_2D_H__

#include "Point2D.h"
#include "Vector2D.h"

class Line2D {
  public:
    Line2D ();
    Line2D (Float32 rho, Float32 theta);
    Line2D (Float32 a, Float32 b, Float32 c);
    Line2D (const Point2D& p1, const Point2D& p2);
    virtual ~Line2D ();

    Float32 getSlope () const;
    Float32 getYIntercept () const;
    Float32 getXIntercept () const;
    Float32 getRho () const;
    Float32 getTheta () const;

    Float32 getXValue (Float32 y) const;
    Float32 getYValue (Float32 x) const;

    Point2D getIntersection (const Line2D& line) const;
    Line2D getPerpendicular (const Point2D& p) const;

    void translate (const Vector2D& v);

    Float32 valueAt (const Point2D& p) const;
  protected:
    // General Form ax+by+c=0
    Float32 m_a;
    Float32 m_b;
    Float32 m_c;
};

#endif
