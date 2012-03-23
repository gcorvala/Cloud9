#ifndef __LINE_PROJECTOR_H__
#define __LINE_PROJECTOR_H__

#include "Projector.h"
#include "Point2D.h"
#include "../2D/Line.h"

template <typename T>
class LineProjector : public Projector < Point2D <T> > {
  public:
    LineProjector ();
    virtual ~LineProjector ();

    Line getLine () const;
    void setLine (const Line& line);

  protected:
    Point2D <T> project (const Point2D <T>& point) const;

    Line m_line;
};

template <typename T>
LineProjector <T>::LineProjector ()
  :m_line (1, -1, 0)
{
}

template <typename T>
LineProjector <T>::~LineProjector ()
{
}

template <typename T>
Line
LineProjector <T>::getLine () const
{
  return m_line;
}

template <typename T>
void
LineProjector <T>::setLine (const Line& line)
{
  m_line = line;
}

template <typename T>
Point2D <T>
LineProjector <T>::project (const Point2D <T>& point) const
{
#if 0
  Float64 m = m_line.getSlope ();
  Float64 b = m_line.getYIntercept ();
  Float64 x = (m*point.y+point.x-m*b)/(m*m+1);
  Float64 y = (m*m*point.y+m*point.x+b)/(m*m+1);
#else
  Line perp = m_line.getPerpendicular (Point (point.x, point.y));
  Point p = m_line.getIntersection (perp);
//  Float64 y = ((m_line.a*m_line.a+m_line.b*m_line.b)/(m_line.a*m_line.b))*((m_line.c/m_line.a)+point.x+(m_line.a/m_line.b)*point.y);
//  Float64 x = -(m_line.b*y+m_line.c)/m_line.a;
  Float64 x = p.x;
  Float64 y = p.y;
  
#endif
  return Point2D <T> (x, y);
}

#endif