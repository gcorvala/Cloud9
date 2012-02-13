#include "Line.h"

#include <math.h>
#include <limits>
#include <iostream>

Line::Line ()
  :a(1)
  ,b(0)
  ,c(0)
{
}

Line::Line (double rho, double theta)
  :a(cos (theta))
  ,b(sin (theta))
  ,c(-rho)
{
//  std::cout << "a:" << a << " b:" << b << " c:" << c;
  std::cout << " slope:" << getSlope () << " y_intercept:" << getYIntercept () << " x_intercept:" << getXIntercept () << std::endl;
  std::cout << " rho:" << getRho () << " theta:" << getTheta () << std::endl;
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
  double slope;

  slope = -a/b;

  return slope;
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
  return -c;
}

double
Line::getTheta () const
{
  double theta = atan2 (b, a);
  if (theta < 0) {
    theta += M_PI;
  }
  return theta;
}

double
Line::getXValue (double y) const
{
  return -(b*y+c)/a;
}

double
Line::getYValue (double x) const
{
  return -(a*x+c)/b;
}