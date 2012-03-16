#ifndef __SEARCH_T_H__
#define __SEARCH_T_H__

#include "PointCloudT.h"
#include "FilterIndices.h"
#include "../Common/Types.h"

template <class PointT>
class SearchT {
  public:
    SearchT ();
    virtual ~SearchT ();

    virtual void setInputCloud (const PointCloudT <PointT>& cloud);
    virtual UInt32 nearestKSearch (const PointT& p, UInt32 k, PointIndices& k_indices, std::vector <Float64>& k_squared_distances) const = 0;
    virtual UInt32 radiusSearch (const PointT& p, Float64 radius, PointIndices& k_indices, std::vector <Float64>& k_squared_distances) const = 0;

    virtual SearchT* clone () const = 0;

  protected:
    const PointCloudT <PointT> *m_cloud;
};

template <class PointT>
SearchT <PointT>::SearchT ()
  :m_cloud (NULL)
{
}

template <class PointT>
SearchT <PointT>::~SearchT ()
{
}

template <class PointT>
void
SearchT <PointT>::setInputCloud (const PointCloudT <PointT>& cloud)
{
  m_cloud = &cloud;
}

#endif