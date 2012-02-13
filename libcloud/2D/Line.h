#ifndef __LINE_H__
#define __LINE_H__

#include "../Common/Point.h"

class Line {
  public:
    Line ();
    //Line (double slope, double y_intercept);
    //static Line& createFrom (double slope, double y_intercept);
    Line (double rho, double theta);
    Line (double _a, double _b, double _c);
    virtual ~Line ();

    double getSlope () const;
    double getYIntercept () const;
    double getXIntercept () const;
    double getRho () const;
    double getTheta () const;

    double getXValue (double y) const;
    double getYValue (double x) const;

    bool contains (const Point& p, double epsilon = 0) const;
    bool isVertical () const;
    bool isHorizontal () const;

    Point getIntersection () const;
  protected:
    // FIXME : Forme ax+by+c=0
    double a;
    double b;
    double c;
};

#endif