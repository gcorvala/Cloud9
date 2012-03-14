#ifndef __LINE_INLIERS_T_H__
#define __LINE_INLIERS_T_H__

#include "FilterIndicesT.h"
#include "../2D/Line.h"

template <typename T>
class LineInliersT : public FilterIndicesT < Point2D <T> > {
  public:
    LineInliersT ();
    virtual ~LineInliersT ();

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
LineInliersT <T>::LineInliersT ()
  :m_line (1, -1, 0)
  ,m_distance_threshold (0)
{
}

template <typename T>
LineInliersT <T>::~LineInliersT ()
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
LineInliersT <T>::compute (const PointCloudT < Point2D <T> >& input, PointIndices& indices) const
{
  indices.clear ();

  for (UInt32 i = 0; i < input.size (); ++i) {
    std::cout << distanceLinePoint (m_line, input[i]) << std::endl;
    if (distanceLinePoint (m_line, input[i]) <= m_distance_threshold) {
      indices.push_back (i);
    }
  }
}

template <typename T>
Line
LineInliersT <T>::getLine () const
{
  return m_line;
}

template <typename T>
void
LineInliersT <T>::setLine (const Line& line)
{
  m_line = line;
}

template <typename T>
Float64
LineInliersT <T>::getDistanceThreshold () const
{
  return m_distance_threshold;
}

template <typename T>
void
LineInliersT <T>::setDistanceThreshold (Float64 distance_threshold)
{
  m_distance_threshold = distance_threshold;
}

#endif