#ifndef __FILTER_H__
#define __FILTER_H__

#include "../Common/PointCloud3D.h"

class Filter {
  public:
    Filter ();
    virtual ~Filter ();

    virtual void compute (PointCloud3D& output) const = 0;
    void compute (const PointCloud3D& input, PointCloud3D& output);

    const PointCloud3D& getInputCloud () const;
    void setInputCloud (const PointCloud3D& cloud);

    const Indices& getInputIndices () const;
    void setInputIndices (const Indices& indices);

    UInt32 getInputSize () const;
    UInt32 getInputIndex (UInt32 i) const;

  protected:
    const Point3D& operator[] (UInt32 i) const;

    Indices m_input_indices;
    PointCloud3D::const_ptr m_input_cloud;
};

#endif