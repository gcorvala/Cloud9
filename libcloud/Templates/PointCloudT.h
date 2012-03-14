#ifndef __POINT_CLOUD_T_H__
#define __POINT_CLOUD_T_H__

#include <vector>

template <class PointT>
class PointCloudT : public std::vector <PointT> {
  public:
    //typedef typename std::vector <PointT>::iterator iterator;
    //typedef typename std::vector <PointT>::const_iterator const_iterator;

    PointCloudT ();
    virtual ~PointCloudT ();
  protected:
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