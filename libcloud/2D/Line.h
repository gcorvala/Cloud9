#ifndef __LINE_H__
#define __LINE_H__

#include "../Common/Point.h"
#include "../Common/Vector.h"

class Line {
  public:
    Line ();
    //Line (Float64 slope, Float64 y_intercept);
    //static Line& createFrom (Float64 slope, Float64 y_intercept);
    Line (Float64 rho, Float64 theta);
    Line (Float64 _a, Float64 _b, Float64 _c);
    virtual ~Line ();

    Float64 getSlope () const;
    Float64 getYIntercept () const;
    Float64 getXIntercept () const;
    Float64 getRho () const;
    Float64 getTheta () const;

    Float64 getXValue (Float64 y) const;
    Float64 getYValue (Float64 x) const;

    bool contains (const Point& p, Float64 epsilon = 0) const;
    bool isVertical () const;
    bool isHorizontal () const;

    Point getIntersection () const;

    void translate (const Vector& v);
  //protected:
    // FIXME : Forme ax+by+c=0
    Float64 a;
    Float64 b;
    Float64 c;
};

#endif