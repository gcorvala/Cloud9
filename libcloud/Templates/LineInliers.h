#ifndef __LINE_INLIERS_H__
#define __LINE_INLIERS_H__

#include "FilterIndices.h"
#include "../2D/Line.h"

template <typename T>
class LineInliers : public FilterIndices < Point2D <T> > {
  public:
    LineInliers ();
    virtual ~LineInliers ();

    void compute (const PointCloudT < Point2D <T> >& input, PointIndices& indices) const;
  
    Line getLine () const;
    void setLine (const Line& line);

    Float64 getDistanceThreshold () const;
    void setDistanceThreshold (Float64 distance_threshold);

  protected:
    Line m_line;
    Float64 m_distance_threshold;
};

template <typename T>
LineInliers <T>::LineInliers ()
  :m_line (1, -1, 0)
  ,m_distance_threshold (0)
{
}

template <typename T>
LineInliers <T>::~LineInliers ()
{
}

// FIXME !
#include <math.h>

template <typename T>
Float64
distanceLinePoint (const Line& line, const Point2D <T>& point)
{
  return fabs (line.a*point.x+line.b*point.y+line.c)/hypot (line.a, line.b);
}

template <typename T>
void
LineInliers <T>::compute (const PointCloudT < Point2D <T> >& input, PointIndices& indices) const
{
  indices.clear ();

  for (UInt32 i = 0; i < input.size (); ++i) {
    if (distanceLinePoint (m_line, input[i]) <= m_distance_threshold) {
      indices.push_back (i);
    }
  }
}

template <typename T>
Line
LineInliers <T>::getLine () const
{
  return m_line;
}

template <typename T>
void
LineInliers <T>::setLine (const Line& line)
{
  m_line = line;
}

template <typename T>
Float64
LineInliers <T>::getDistanceThreshold () const
{
  return m_distance_threshold;
}

template <typename T>
void
LineInliers <T>::setDistanceThreshold (Float64 distance_threshold)
{
  m_distance_threshold = distance_threshold;
}

#endif