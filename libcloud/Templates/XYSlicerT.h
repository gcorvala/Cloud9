#ifndef __XY_SLICER_T_H__
#define __XY_SLICER_T_H__

#include "SlicerT.h"
#include "../Common/Types.h"
#include "PointCloudT.h"
#include <vector>
#include <limits>

template <class PointT>
class XYSlicerT : public SlicerT <PointT> {
  public:
    XYSlicerT (Float64 thickness);
    virtual ~XYSlicerT ();

    void compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const;
};

template <class PointT>
XYSlicerT <PointT>::XYSlicerT (Float64 thickness)
  :SlicerT <PointT> (thickness)
{
}

template <class PointT>
XYSlicerT <PointT>::~XYSlicerT ()
{
}

template <class PointT>
void
XYSlicerT <PointT>::compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const
{
  typename PointCloudT <PointT>::const_iterator it;

  output.clear ();

  Float64 min = std::numeric_limits <Float64>::max ();
  Float64 max = std::numeric_limits <Float64>::min ();

  for (it = input.begin (); it != input.end (); ++it) {
    if (it->z > max) {
      max = it->z;
    }
    if (it->z < min) {
      min = it->z;
    }
  }

  UInt32 nb_slice = floor ((max-min)/SlicerT <PointT>::m_thickness)+1;

  output.resize (nb_slice);

  for (it = input.begin (); it != input.end (); ++it) {
    UInt32 slice_idx = floor ((it->z-min)/SlicerT <PointT>::m_thickness);
    output[slice_idx].push_back (*it);
  }
}

#endif