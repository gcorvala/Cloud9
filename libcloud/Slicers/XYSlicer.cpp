#include "XYSlicer.h"

#include <math.h>

XYSlicer::XYSlicer (Float64 thickness, UInt32 resolution)
  :Slicer(thickness, resolution)
{
}

XYSlicer::~XYSlicer ()
{
}

void
XYSlicer::compute (const PointCloud& input, std::vector<PointCloud>& output) const
{
  PointCloud::const_iterator it;

  output.clear ();
  
  Float64 min = input.getMin ().z;
  Float64 max = input.getMax ().z;

  UInt32 nb_slice = floor ((max-min)/m_thickness)+1;

  output.resize (nb_slice);

  for (it = input.begin (); it != input.end (); ++it) {
    UInt32 slice_idx = floor ((it->z-min)/m_thickness);
    output[slice_idx].push_back (*it);
  }
}
