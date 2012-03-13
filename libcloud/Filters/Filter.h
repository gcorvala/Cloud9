#ifndef __FILTER_H__
#define __FILTER_H__

#include "../Common/PointCloud.h"

class Filter {
  public:
    Filter ();
    virtual ~Filter ();
    virtual void run (PointCloud& cloud) const = 0;
    virtual void compute (const PointCloud& input, PointCloud& output) const = 0;

  protected:
    PointCloud removed;
    double limit_min;
    double limit_max;
};

template <class PointT>
class FilterT {
  public:
    FilterT ();
    virtual ~FilterT ();
    virtual void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const = 0;
  protected:
};

template <class PointT>
class FilterIndices : public FilterT <PointT> {
  public:
    typedef std::vector <UInt32> PointIndices;

    FilterIndices ();
    virtual ~FilterIndices ();
    virtual void compute (const PointCloudT <PointT>& input, PointIndices& indices);
  protected:
};

template <class PointT>
class ExtractIndices : public FilterIndices <PointT> {
  public:
    typedef std::vector <SInt32> ModelCoefficients;

    ExtractIndices ();
    virtual ~ExtractIndices ();

    void setModelCoefficients (const ModelCoefficients& coefficients);
    ModelCoefficients& getModelCoefficients () const;

  protected:
};

#endif