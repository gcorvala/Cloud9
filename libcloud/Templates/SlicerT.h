#ifndef __SLICER_T_H__
#define __SLICER_T_H__

#include "../Common/Types.h"
#include "PointCloudT.h"
#include <vector>

template <class PointT>
class SlicerT {
  public:
    SlicerT (Float64 thickness);
    virtual ~SlicerT ();
    virtual void compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const = 0;

    Float64 getThickness () const;
    void setThickness (Float64 thickness);

  protected:
    Float64 m_thickness;
};

template <class PointT>
SlicerT <PointT>::SlicerT (Float64 thickness)
  :m_thickness (thickness)
{
}

template <class PointT>
SlicerT <PointT>::~SlicerT ()
{
}

template <class PointT>
Float64
SlicerT <PointT>::getThickness () const
{
  return m_thickness;
}

template <class PointT>
void
SlicerT <PointT>::setThickness (Float64 thickness)
{
  m_thickness = thickness;
}

#endif