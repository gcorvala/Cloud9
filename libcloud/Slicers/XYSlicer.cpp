#include "XYSlicer.h"

#include "../Common/Box.h"
#include "../Filters/CropBoxFilter.h"

XYSlicer::XYSlicer (Float64 thickness, UInt32 resolution)
  :Slicer(thickness, resolution)
{
}

XYSlicer::~XYSlicer ()
{
}

void
XYSlicer::compute (const PointCloud& input, std::vector<Matrix<UInt8> >& output) const
{
  CropBoxFilter crop;
  PointCloud crop_cloud;
  Point min (input.getMin ());
  Point max (input.getMax ());
  Float64 max_z = max.z;
  max.z = min.z + m_thickness;
  Float64 x_step = (max.x-min.x)/m_resolution;
  Float64 y_step = (max.y-min.y)/m_resolution;

  output.clear ();

  while (min.z < max_z) {
    Matrix<UInt8> mat (m_resolution, m_resolution);
    crop.setMin (min);
    crop.setMax (max);
    crop.compute (input, crop_cloud);
    min.z += m_thickness;
    max.z += m_thickness;
    output.push_back (mat);
  }
}
