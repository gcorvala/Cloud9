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
  Float64 m = m_line.getSlope ();
  Float64 b = m_line.getYIntercept ();
  Float64 x = (m*point.y+point.x-m*b)/(m*m+1);
  Float64 y = (m*m*point.y+m*point.x+b)/(m*m+1);
  return Point2D <T> (x, y);
}

#endif