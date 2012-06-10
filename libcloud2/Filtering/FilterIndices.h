#ifndef __FILTER_INDICES_H__
#define __FILTER_INDICES_H__

#include "Filter.h"

class FilterIndices : public Filter {
  public:
    FilterIndices ();
    virtual ~FilterIndices ();

    using Filter::compute;
    virtual void compute (Indices &indices) const = 0;
    void compute (PointCloud3D& output) const;
    void compute (const PointCloud3D& input, Indices& indices);

    Boolean getNegative () const;
    void setNegative (Boolean negative);

  protected:
    Boolean m_negative;
};

#endif