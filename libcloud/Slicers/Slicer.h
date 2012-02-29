#ifndef __SLICE_FILTER_H__
#define __SLICE_FILTER_H__

#include "../Common/Types.h"
#include "../Common/PointCloud.h"
#include <vector>

class Slicer {
  public:
    Slicer (Float64 thickness, UInt32 resolution);
    virtual ~Slicer ();
    virtual void compute (const PointCloud& input, std::vector<PointCloud>& output) const = 0;

    Float64 getThickness () const;
    void setThickness (Float64 thickness);

  protected:
    Float64 m_thickness;
    UInt32 m_resolution;
};

#endif