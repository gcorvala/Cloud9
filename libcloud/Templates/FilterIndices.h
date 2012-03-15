#ifndef __FILTER_INDICES_H__
#define __FILTER_INDICES_H__

#include "Filter.h"
#include "PointCloudT.h"
#include "../Common/Types.h"

typedef std::vector <UInt32> PointIndices;

template <class PointT>
class FilterIndices : public Filter <PointT> {
  public:

    FilterIndices ();
    virtual ~FilterIndices ();

    void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const;
    virtual void compute (const PointCloudT <PointT>& input, PointIndices& indices) const = 0;
};

template <class PointT>
FilterIndices <PointT>::FilterIndices ()
{
}

template <class PointT>
FilterIndices <PointT>::~FilterIndices ()
{
}

template <class PointT>
void
FilterIndices <PointT>::compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const
{
  PointIndices indices;

  output.clear ();

  compute (input, indices);

  for (PointIndices::const_iterator it = indices.begin (); it != indices.end (); ++it) {
    output.push_back (input[*it]);
  }
}

#endif