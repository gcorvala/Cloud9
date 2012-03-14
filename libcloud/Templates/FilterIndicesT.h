#ifndef __FILTER_INDICES_T_H__
#define __FILTER_INDICES_T_H__

#include "FilterT.h"
#include "PointCloudT.h"
#include "../Common/Types.h"

typedef std::vector <UInt32> PointIndices;

template <class PointT>
class FilterIndicesT : public FilterT <PointT> {
  public:

    FilterIndicesT ();
    virtual ~FilterIndicesT ();

    void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const;
    virtual void compute (const PointCloudT <PointT>& input, PointIndices& indices) const = 0;
};

template <class PointT>
FilterIndicesT <PointT>::FilterIndicesT ()
{
}

template <class PointT>
FilterIndicesT <PointT>::~FilterIndicesT ()
{
}

template <class PointT>
void
FilterIndicesT <PointT>::compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const
{
  PointIndices indices;

  output.clear ();

  compute (input, indices);

  for (PointIndices::const_iterator it = indices.begin (); it != indices.end (); ++it) {
    output.push_back (input[*it]);
  }
}

#endif