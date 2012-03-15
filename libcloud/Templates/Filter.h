#ifndef __FILTER_H__
#define __FILTER_H__

#include "PointCloudT.h"

template <class PointT>
class Filter {
  public:
    Filter ();
    virtual ~Filter ();
    virtual void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const = 0;
};

template <class PointT>
Filter <PointT>::Filter ()
{
}

template <class PointT>
Filter <PointT>::~Filter ()
{
}

#endif