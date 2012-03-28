#ifndef __YZ_SLICER_T_H__
#define __YZ_SLICER_T_H__

#include "SlicerT.h"
#include "../Common/Types.h"
#include "PointCloudT.h"
#include <vector>
#include <limits>
#include <math.h>

template <class PointT>
class YZSlicerT : public SlicerT <PointT> {
  public:
    YZSlicerT (Float64 thickness);
    virtual ~YZSlicerT ();

    void compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const;
};

template <class PointT>
YZSlicerT <PointT>::YZSlicerT (Float64 thickness)
  :SlicerT <PointT> (thickness)
{
}

template <class PointT>
YZSlicerT <PointT>::~YZSlicerT ()
{
}

template <class PointT>
void
YZSlicerT <PointT>::compute (const PointCloudT <PointT>& input, std::vector < PointCloudT <PointT> >& output) const
{
  typename PointCloudT <PointT>::const_iterator it;

  output.clear ();

  Float64 min = std::numeric_limits <Float64>::max ();
  Float64 max = std::numeric_limits <Float64>::min ();

  for (it = input.begin (); it != input.end (); ++it) {
    if (it->x > max) {
      max = it->x;
    }
    if (it->x < min) {
      min = it->x;
    }
  }

  UInt32 nb_slice = floor ((max-min)/SlicerT <PointT>::m_thickness)+1;

  output.resize (nb_slice);

  for (it = input.begin (); it != input.end (); ++it) {
    UInt32 slice_idx = floor ((it->x-min)/SlicerT <PointT>::m_thickness);
    output[slice_idx].push_back (*it);
  }
}

#endif