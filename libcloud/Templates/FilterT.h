#ifndef __FILTER_T_H__
#define __FILTER_T_H__

#include "PointCloudT.h"

template <class PointT>
class FilterT {
  public:
    FilterT ();
    virtual ~FilterT ();
    virtual void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const = 0;
};

template <class PointT>
FilterT <PointT>::FilterT ()
{
}

template <class PointT>
FilterT <PointT>::~FilterT ()
{
}

#endif