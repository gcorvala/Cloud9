#ifndef __XZ_SLICER_T_H__
#define __XZ_SLICER_T_H__

#include "SlicerT.h"
#include "../Common/Types.h"
#include "PointCloudT.h"
#include <vector>
#include <limits>
#include <math.h>

template <class PointT>
class XZSlicerT : public SlicerT <PointT> {
  public:
    XZSlicerT (Float64 thickness);
    virtual ~XZSlicerT ();

    void compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const;
};

template <class PointT>
XZSlicerT <PointT>::XZSlicerT (Float64 thickness)
  :SlicerT <PointT> (thickness)
{
}

template <class PointT>
XZSlicerT <PointT>::~XZSlicerT ()
{
}

template <class PointT>
void
XZSlicerT <PointT>::compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const
{
  typename PointCloudT <PointT>::const_iterator it;

  output.clear ();

  Float64 min = std::numeric_limits <Float64>::max ();
  Float64 max = std::numeric_limits <Float64>::min ();

  for (it = input.begin (); it != input.end (); ++it) {
    if (it->y > max) {
      max = it->y;
    }
    if (it->y < min) {
      min = it->y;
    }
  }

  UInt32 nb_slice = floor ((max-min)/SlicerT <PointT>::m_thickness)+1;

  output.resize (nb_slice);

  for (it = input.begin (); it != input.end (); ++it) {
    UInt32 slice_idx = floor ((it->y-min)/SlicerT <PointT>::m_thickness);
    output[slice_idx].push_back (*it);
  }
}

#endif