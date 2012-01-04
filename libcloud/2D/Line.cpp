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
  return atan2 (b, a);
}