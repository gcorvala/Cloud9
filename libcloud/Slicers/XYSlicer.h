#ifndef __XY_SLICE_FILTER_H__
#define __XY_SLICE_FILTER_H__

#include "Slicer.h"
#include "../Common/Types.h"
#include "../Common/PointCloud.h"
#include <vector>

class XYSlicer : public Slicer {
  public:
    XYSlicer (Float64 thickness, UInt32 resolution);
    virtual ~XYSlicer ();
    void compute (const PointCloud& input, std::vector<PointCloud>& output) const;
};

#endif