#ifndef __LINE_PROJECTOR_T_H__
#define __LINE_PROJECTOR_T_H__

#include "ProjectorT.h"
#include "Point2D.h"
#include "../2D/Line.h"

template <typename T>
class LineProjectorT : public ProjectorT < Point2D <T> > {
  public:
    LineProjectorT ();
    virtual ~LineProjectorT ();

  protected:
    Point2D <T> project (const Point2D <T>& point) const;

    Line m_line;
};

template <typename T>
LineProjectorT <T>::LineProjectorT ()
  :m_line (1, -1, 0)
{
}

template <typename T>
LineProjectorT <T>::~LineProjectorT ()
{
}

template <typename T>
Point2D <T>
LineProjectorT <T>::project (const Point2D <T>& point) const
{
  Float64 m = m_line.getSlope ();
  Float64 b = m_line.getYIntercept ();
  Float64 x = (m*point.y+point.x-m*b)/(m*m+1);
  Float64 y = (m*m*point.y+m*point.x+b)/(m*m+1);
  return Point2D <T> (x, y);
}

#endif