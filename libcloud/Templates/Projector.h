#ifndef __PROJECTOR_H__
#define __PROJECTOR_H__

#include "Filter.h"

template <class PointT>
class Projector : public Filter <PointT> {
  public:
    Projector ();
    virtual ~Projector ();

    void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const;

  protected:
    virtual PointT project (const PointT& point) const = 0;
};

template <class PointT>
Projector <PointT>::Projector ()
{
}

template <class PointT>
Projector <PointT>::~Projector ()
{
}

template <class PointT>
void
Projector <PointT>::compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const
{
  typename PointCloudT <PointT>::const_iterator it;

  output.clear ();

  for (it = input.begin (); it != input.end (); ++it) {
    output.push_back (project (*it));
  }
}

#endif