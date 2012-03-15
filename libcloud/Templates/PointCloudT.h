#ifndef __POINT_CLOUD_T_H__
#define __POINT_CLOUD_T_H__

#include <vector>

template <class PointT>
class PointCloudT : public std::vector <PointT> {
  public:
    PointCloudT ();
    virtual ~PointCloudT ();
};

template <class PointT>
PointCloudT <PointT>::PointCloudT ()
{
}

template <class PointT>
PointCloudT <PointT>::~PointCloudT ()
{
}

#endif