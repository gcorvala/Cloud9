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

Line::Line (Float64 rho, Float64 theta)
  :a(cos (theta))
  ,b(sin (theta))
  ,c(-rho)
{
}

Line::Line (Float64 _a, Float64 _b, Float64 _c)
  :a(_a)
  ,b(_b)
  ,c(_c)
{
}

Line::~Line ()
{
}

Float64
Line::getSlope () const
{
  Float64 slope;

  slope = -a/b;

  return slope;
}

Float64
Line::getYIntercept () const
{
  return -c/b;
}

Float64
Line::getXIntercept () const
{
  return -c/a;
}

Float64
Line::getRho () const
{
  return -c;
}

Float64
Line::getTheta () const
{
  Float64 theta;

  theta = atan2 (b, a);
  if (theta < 0) {
    theta += 2.*M_PI;
  }

  return theta;
}

Float64
Line::getXValue (Float64 y) const
{
  return -(b*y+c)/a;
}

Float64
Line::getYValue (Float64 x) const
{
  return -(a*x+c)/b;
}