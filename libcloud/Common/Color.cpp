#include "Color.h"

Color::Color ()
  :r(0)
  ,g(0)
  ,b(0)
{
}

Color::Color (double _r, double _g, double _b)
  :r(_r)
  ,g(_g)
  ,b(_b)
{
}

Color::~Color ()
{
}

Color
Color::operator* (double s) const
{
  return Color (r*s, g*s, b*s);
}

Color
Color::operator+= (const Color c)
{
  r += c.r;
  g += c.g;
  b += c.b;

  return *this;
}

Color
Color::operator* (const Color c) const
{
  return Color (r*c.r, g*c.g, b*c.b);
}

double
Color::getR () const
{
  return r;
}

double
Color::getG () const
{
  return g;
}

double
Color::getB () const
{
  return b;
}

double
Color::getY () const
{
  return 0.299*r+0.587*g+0.114*b;
}

double
Color::getU () const
{
  return -0.14713*r-0.28886*g+0.436*b;
}

double
Color::getV () const
{
  return 0.615*r-0.51498*g-0.10001*b;
}