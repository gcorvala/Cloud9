#include "Line.h"

#include <math.h>

Line::Line ()
  :a(1)
  ,b(0)
  ,c(0)
{
}

Line::Line (double rho, double theta)
  :a(-1/tan (theta))
  ,b(1)
  ,c(rho*sin (theta)+rho*(1/sin (theta)))
{
}

Line::Line (double _a, double _b, double _c)
  :a(_a)
  ,b(_b)
  ,c(_c)
{
}

Line::~Line ()
{
}

double
Line::getSlope () const
{
  return -a/b;
}

double
Line::getYIntercept () const
{
  return -c/b;
}

double
Line::getXIntercept () const
{
  return -c/a;
}

double
Line::getRho () const
{
  double theta = getTheta ();
  return c/(sin (theta)+sin (theta)*sin (theta));
}

double
Line::getTheta () const
{
  return atan (b/a);
}

/*bool contains (const Point& p) const;
bool isVertical () const;
bool isHorizontal () const;

Point getIntersection () const;*/
